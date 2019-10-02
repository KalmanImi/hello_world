#include "std_lib_facilities.h"
#include <iostream>
#include <unistd.h>




char byte1;
char byte2;
char byte3;

int xlen = 30;
int ylen = 20;
int byte_len = 128;
string kiirando;
string kitolto = "-";
vector<string> mentendo;

void drawline() {
    for (int x = 0; x <= xlen; x++) {
        //cout << 'X';
    }
    //cout << '\n';
}

int main() {
    
    int kezdox;
    int kezdoy;
    cout << "Adja meg a kezdőértékeket térközzel elválasztva!\n";
    cout << "Az első érték maximuma 32, a másodiké 21 lehet!\n";
    while (kezdox < 0 || kezdox > 32 || kezdoy < 0 || kezdoy > 21){
        cin >> kezdox >> kezdoy;
    }

    for (int i = 0; i <= ylen+1; i++) {
        for(int j = 0; j <= xlen+2; j++) {
            mentendo.push_back(kitolto);
        }
        mentendo.push_back("\n");
    }
    
    
 
    
    //int kezdox = 2;
    //int kezdoy = 10;
    
 
    int lepesx = abs(kezdox*(byte_len/xlen));
    int lepesy = abs(kezdoy*(byte_len/ylen));
    while (true) {
        
        byte1 = lepesx;
        byte2 = lepesy;
        int szam1 = abs(byte1/(byte_len/xlen));
        int szam2 = abs(byte2/(byte_len/ylen));
        //cout << szam1 << " " << szam2 << '\n';
        lepesx+=byte_len/xlen;
        lepesy+=byte_len/ylen;
        
        mentendo[szam1 + szam2*(xlen+4)] = "O";
        
        kiirando = "";
        for (int i = 0; i < mentendo.size(); i++) {
            kiirando += mentendo[i];
        }
        
        
        //cout << string(kiirando.size(),'\b');
        cout  << kiirando;
        
        mentendo[szam1 + szam2*(xlen+4)] = " ";
        //drawline();   
        usleep(50000);  
        system("clear");  
    }
    
    /*
    for(int i = 0; i <= bytelen*xlen; i+=bytelen/xlen) {
        byte1 = i;
        int szam = abs(byte1/(bytelen/xlen));
        cout << szam << '\n';
    }
    */
    
}
