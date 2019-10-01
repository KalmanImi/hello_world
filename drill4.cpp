#include "std_lib_facilities.h"


double first_value;     // <-- 4.
double second_value;    // <-- 4.
string unit;
int number_of_values = 0;
double sum_of_values = 0;
vector<double> values_in_meter;

double convert_to_meter (double value, string unit) {
    
    const double cm_to_meter = 1.0/100;
    const double in_to_meter = 1.0/100*2.54;
    const double ft_to_meter = 1.0/100*2.54*12;
    
    double converted;
    if (unit == "cm") {converted = value * cm_to_meter;}
    else if (unit == "in") {converted = value * in_to_meter;}
    else if (unit == "ft") {converted = value * ft_to_meter;}
    else if (unit == "m") {converted = value;}
    return converted;
}


int main () {
    
    cout << "Enter a value and a unit separated by space (cm, m, in, ft).\n";
    cin >> first_value >> unit;
    double smallest = convert_to_meter(first_value, unit);
    //double smallest = first_value;
    double largest = smallest;
    number_of_values += 1;
    sum_of_values += convert_to_meter(first_value, unit);

    
    /*
    cout << "Enter two numbers separated by enter.\n";
    
    while (cin >> first_value >> second_value) {        // <-- 1.
        if (first_value < second_value) {               // <-- 2.        
            cout << "the smaller value is: " << first_value << 
            "\nthe larger value is: " << second_value << '\n';
            if ((second_value - first_value) < 1.0/10000000) {  // <-- 5.
                cout << "\nthe numbers are almost equal\n";
            }
        }
        else if (second_value < first_value) {          // <-- 2.
            cout << "the smaller value is: " << second_value << 
            "\nthe larger value is: " << first_value << '\n';
            if ((first_value - second_value) < 1.0/10000000) {  // <-- 5.
                cout << "\nthe numbers are almost equal\n";
            }
        }
        else if (second_value == first_value) {
            cout << "the numbers are equals\n";         // <-- 3.
        }
    }
    */
    while (cin >> first_value >> unit) {
        if (unit == "y" || unit == "yard" || unit == "meter" || unit == "km" || unit == "gallons") {cout << "Invalid unit. Please enter cm, m, in or ft!\n";} 
        else if (unit == "cm" || unit == "m" || unit == "in" || unit == "ft") {
            double value_in_meter = convert_to_meter (first_value, unit);
            values_in_meter.push_back(value_in_meter);
            //cout << value_in_meter << '\n';
            //cout << first_value << unit << '\n';
            number_of_values += 1;
            sum_of_values += convert_to_meter(first_value, unit);
            if (value_in_meter < smallest) {
                smallest = value_in_meter;
                cout << first_value << unit << " is the smallest so far\n";  //<-- 6
            }
            if (value_in_meter > largest) {
                largest = value_in_meter;
                cout << first_value << unit << " is the largest so far\n";  // <-- 6
            }
        }
    }
    cout << "smallest: " << smallest << " m, largest: " << largest << 
" m, number of values: " << number_of_values << ", sum of values: " << 
sum_of_values << " m\n\n";
    sort(values_in_meter);
    for (int i = 0; i < values_in_meter.size(); i++) {
        cout << values_in_meter[i] << "m, ";
    }
    
}
