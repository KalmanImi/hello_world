#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void usage (void){
    std::cout << "Usage: lzwtree in_file -o out_file" << std::endl;
}

//Bitek betöltése
vector<char> beTolt(char* inFile) {
	vector<char> filebin;
	fstream beFile (inFile, ios_base::in);
	unsigned char b;
		
	while(beFile.read ((char *) &b, sizeof (unsigned char))){
	if (b == 0x3e) continue;
	if (b == 0x0a) continue;
	if (b == 0x4e) continue;
		for (int i = 0; i < 8; ++i){
			filebin.push_back(b & 0x80?'1':'0');
			b <<= 1;
		}
	}
	beFile.close();
	return filebin;
}

//Tördelés
void tordel(vector<char> &filebin,vector<string> &q,vector<int> &p) {
	int i = 0;
	while(i < filebin.size()){
		if (q.size() == 0) {
			q.push_back(string(1,filebin[i]));
			p.push_back(1);
			i+=1;
		}
		bool jelzo = false;
		for (int j = q.size()-1; j >= 0; j--){
			int num = 0;
			bool breakj = false;
			string temp;
			for (int k = 0; k < q[j].size(); k++){
				if (q[j][k] == filebin[i+k]){
					jelzo = true;
					num += 1;
					temp += filebin[i+k];
				}
				if (num == q[j].size()){
					if ((i+k) != filebin.size()-1){
						p.push_back(temp.size()+1);
						temp += filebin[i+k+1];
						q.push_back(temp);
						i+=q[j].size()+1;
						breakj = true;
						break;
					} else i+=q[j].size()+1; 
				}
			}
			if (breakj == true){
				break;
			}
		}
		if (jelzo == false) {
			q.push_back(string(1,filebin[i]));
			p.push_back(1);
			i+=1;
		}
	}
}

//A binfa ágvégeinek kiszűrése
void szures(vector<string> &q, vector<int> &p, vector<string> &q1, vector<int> &p1) {
	for (int i = 0; i < q.size(); i++) {
		int k = 0;
		for (int j = 0; j < q.size(); j++) {
			if (q[i] != q[j] && q[i].substr(0,q[i].size()) == q[j].substr(0,q[i].size())) {
				k = 1;
				break;
			}
		}
		if (k == 1) {continue;}
		else { 
			if (k == 0) {
				q1.push_back(q[i]);
				p1.push_back(p[i]);
				continue;
			}
		}
	}
}

//A mélység kiszámítása
int melyseg(vector<int> szamok) {
	int mely = 0;
	for (int i:szamok){
		if (mely < i) mely = i;
	}
	return mely;
}

//Az átlag kiszámítása
double avg (vector<int> szamok) {
	double av = 0.0;
	double mennyi = 0.0;
	for (int i:szamok){
		av+=i;
		mennyi += 1;
	}
	return av/mennyi;
}

//Az empirikus szórásnégyzet kiszámolása
double var (vector<int> szamok, double avg) {
	double vari = 0.0;
	double mennyi = 0.0;
	for (int i:szamok){
		vari += ((i-avg)*(i-avg));
		mennyi += 1;
	}
	return sqrt(vari*(1/(mennyi-1)));
}


vector<char> bitek;		//Ide jönnek a beolvasott bitek
vector<string> tordelt {};	//Ide jön a tördelt sorozat
vector<int> tordelt_melyseg {};	//Ide a tördelt sorozat hosszai
vector<string> tordelt_szurt {};	//Ide a szűrt sorozat
vector<int> tordelt_szurt_melyseg {};	//Ide pedig a szűrt sor. hosszai


int main(int argc, char *argv[]){

	if (argc != 2) return -1;
	char *filename = *++argv;	//A fájlnév a második argumentum	
	bitek = beTolt(filename);	//Bitek betöltése karakterek formájában
	tordel(bitek, tordelt, tordelt_melyseg);	//Tördelés
	szures(tordelt, tordelt_melyseg, tordelt_szurt, tordelt_szurt_melyseg);		//Végek kiszűrése
	int mely = melyseg(tordelt_szurt_melyseg);	//Mélység kisz
	double atlag = avg(tordelt_szurt_melyseg);	//Átlag kisz
	double szoras = var(tordelt_szurt_melyseg,atlag);	//Szórás kisz

	cout << "Mélység: " << mely << endl;
	cout << "Átlag: " << atlag << endl;
	cout << "Empirikus szórásnégyzet: " << szoras << endl;


	return 0;
}
