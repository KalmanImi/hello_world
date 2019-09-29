#include "std_lib_facilities.h"


int main() {
    
    int szohossz = 0;
    int i = 1;
    while (i != 0) {
        i = i << 1;
        szohossz += 1;
    }
    cout << szohossz << '\n';
}
