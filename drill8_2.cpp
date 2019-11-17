#include "std_lib_facilities.h"

void swap_v(int a,int b) {int temp; temp = a; a=b; b = temp;}
void swap_r(int& a,int& b) {int temp; temp = a; a=b; b = temp;}
//void swap_cr(const int& a,const int& b) {try {int temp; temp = a; a=b; b = temp;} catch (exception& e) {cout << e.what() << endl;}}
// Az uccsó függvény nem helyes, ugyanis konstans tagot nem változtathatok meg. Úgy lenne helyes a függvény, ha másolnám a tagjait, azaz az eredeti a és b értéke nem változna. 

void print(int x, int y) {
    cout << x << ' ' << y << endl;
}

int main() {
    int x = 7;
    int y = 9;
    swap_v(x,y); print(x,y);   //Lefut, de nem cseréli meg a beadott értéékeket (csak a másolatukat cseréli)
    swap_r(x,y); print(x,y);    //Lefut és megcseréli a két értéket
    swap_v(7,9);    //Lefut, a másolatot cseréli
    //swap_r(7,9); print(x,y);    //Hibaüzenet!
    const int cx = 7;
    const int cy = 9;
    swap_v(cx,cy); print(cx,cy);    //Mivel másolt értékeket cserél fel, nem ad hibát, nem is változtatja meg az eredeti értékeket
    //swap_r(cx,cy); print(cx,cy);  //Hiba! Konstans nem változtatható meg 
    swap_v(7.7,9.9);  //Lefut, de csak másolatot cserél és egésszé konvertál
    //swap_r(7.7,9.9); print(cx,cy);    //hiba
    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx,dy); print(dx,dy);    //Lefut, de nem cseréli, csak a másolatukat, azokat is egészekre konvertálva
    //swap_r(dx,dy); print(dx,dy);  //hiba
    
}


