#include "std_lib_facilities.h"


int main () {
    
    
    string first_name;
    char friend_sex = 0;
    string friend_name;
    int age;
    /*Ez a régi verzió
    cout << "Írd be a keresztneved!\n";
    cin >> first_name;
    cout << "Hello, " << first_name << '\n';
    */
    
    cout << "Enter the name of the person you want to write to.\n";
    cin >> first_name;
    cout << "Add another friend's name!\n";
    cin >> friend_name;
    cout << "Enter an 'm' if your friend is male and 'f' if your friend is \
female!\n";
    cin >> friend_sex;
    cout << "Enter recipient's age!\n";
    while (age <= 0 || age >= 110) {
        cin >> age;
        if (age <= 0 || age >= 110) {            
            cout << "You are kidding!\n";
        }
    }

    
    cout << "Your letter looks like this:\n\n";

    cout << "Dear " << first_name << ",\n\n";
    cout << "How are you? I haven't seen you in ages. ";
    cout << "\n\nNext friday Omega will arrive to Debrecen and play their bests. \
I know Omega is your favorite band so I think it will be a good idea to take \
part on this event. Would you like to come? I hope your friday evening is \
free.\n\n";

    
    
    cout << "Have you seen " << friend_name << " lately? ";
    
    if (friend_sex == 'm') {cout << "If you see " << friend_name << " please \
ask him to call me.\n";}
    if (friend_sex == 'f') {cout << "If you see " << friend_name << " please \
ask her to call me.\n";}
    
    cout << "\nI hear you just had a birthday and you are " << age << " years old. ";
    
    if (age < 12) {cout << "Next year you will be " << age + 1 << ".\n";}
    else if (age == 17) {cout << "Next year you will be able to vote.\n";}
    else if (age > 70) {cout << "I hope you are enjoying retirement.\n";}
    else {cout << "It is a great number.\n";}

    cout << "\nYours sincerely,\n\n\nImre\n";
}

