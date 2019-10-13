#include "std_lib_facilities.h"

int main() {


//  1.
cout << "Success!\n";   //C --> c


//  2.
cout << "Success!\n";   // --> "


//  3.
cout << "Success" << "!\n"; // --> "


//  4.
string success = "Success!";    // success változó

cout << success << endl;

//  5.
int res = 7;    //string --> int
vector<int> v(10);
v[5] = res;
cout << "Success!\n";


//  6.
vector<int> a(10);  // v --> a
a[5] = 7;   // () --> []
    if (a[5] == 7) cout << "Success!\n";    // () --> []


//  7.
int cond = 1;   // cond változó bevezetése, ami 1-el egyenlő.
    if (cond) cout << "Success!\n";
    else cout << "Fail!\n";


//  8.
bool c = false;
    if (c+1) cout << "Success!\n";  // 0: hamis, 1:igaz --> c+1 = igaz
    else cout << "Fail!\n";


//  9.  ?
string s = "ape";
bool d = "fool" < s;
    if (d) cout << "Success!\n";


//  10.
string s1 = "ape";
if (s1 <= "fool") cout << "Success!\n";


//  11. ?
string s2 = "ape";
if (s2 == "fool") cout << "Success!\n";


//  12. 
string s3 = "ape";
    if ((s3 + "fool").length() > s3.length()) cout << "Success!\n"; 


//  13.
vector<char> v1(5);
for (int i = 0; i < v1.size(); ++i) cout << "Success!\n";


//  14.
vector<char> v2(5);
for (int i = 0; i <= v2.size(); ++i) cout << "Success!\n";


//  15.
string s4 = "Success!\n";
for (int i = 0; i < s4.size(); ++i) cout << s4[i];  // 6 --> s4.size()


//  16.
if (true) cout << "Success!\n"; else cout << "Fail!\n"; // then --> ""


//  17.
int x = 2000;
double c1 = x;    // Helytelen konverzió! char --> double
if (c1 == 2000) cout << "Success!\n";


//  18.
string s5 = "Success!\n";
for (int i = 0; i < 10; ++i) cout << s5[i];


//  19.
vector<int> v3(5);  // Hiányzott a típus
for (int i = 0; i < v3.size(); ++i) cout << "Success!\n";   // ; --> ""


//  20.
int i = 0;
int j = 9;
while (i <= j) {     
    --j;
    if (j == i) cout << "Success!\n";    
}


//  21.
int x1 = 3;
try {
    double d1 = 5/(x1-2);
    if (d1 == 2*x1+0.5) cout << "Success!\n";
}
catch (exception& e) {
    cout << "Error founded. Success!\n";
}


//  22.
string s6 = "Success!\n";
for (int i = 0; i <= 10; ++i) cout << s6[i];


//  23. 
int i1 = 20;
int j1 = 0;  
while (i1 < 21) {
    ++j1;
    if (j1 < i1) {
        cout << "Success!\n";
        break;
    }
}


//  24.
int x2 = 4;
double d2 = 5/(x2-2);
if (d2 != 2*x2+0.5) cout << "Success!\n";


//  25.

cout << "Success!\n";





}
