/** Ez a program a változók cseréjét viszi véghez többféle módon. */

/** A valtozocsere_xor függvény megírásához segítséget a következő oldalakon találtam:

https://riptutorial.com/cplusplus/example/8514/----bitwise-xor--exclusive-or-
https://en.wikipedia.org/wiki/XOR_swap_algorithm

*/    

#include "std_lib_facilities.h"

void valtozocsere_ujvalt(int x, int y) {
    int tmp = x;
    x = y;
    y = tmp;
    cout << "ujvalt: x = " << x << ", y = " << y << '\n';
}


void valtozocsere_xor(int x, int y) {
    if (&x != &y) {    
        x ^= y;
        y ^= x;
        x ^= y;
        cout << "xor: x = " << x << ", y = " << y << '\n';
    }
}


void valtozocsere_kul(int x, int y) {
    x = x + y;
    y = x - y;
    x = x - y;
    cout << "kul: x = " << x << ", y = " << y << '\n';
}


void valtozocsere_szor(int x, int y) {
    x = x * y;
    y = x / y;
    x = x / y;
    cout << "szor: x = " << x << ", y = " << y << '\n';
}



int main() {
    

    int a = 46;
    int b = 25;
    cout << "Az eredeti értékek: a = " << a << ", b = " << b << '\n';

    valtozocsere_ujvalt(a,b);
    valtozocsere_xor(a,b);
    valtozocsere_kul(a,b);
    valtozocsere_szor(a,b);

    return 0;
}
