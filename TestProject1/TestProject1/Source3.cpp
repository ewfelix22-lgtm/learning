#include <string>
#include <limits>
#include <iostream>
using namespace std;
#include <sstream>
string equation;
double number_two;
string version;
double result;

void ZR() {

    if (!(cin >> result)) {
        // No input at all
        return;
    }

    while (true) {
        if (!(cin >> equation >> number_two)) {
            // No more input or invalid input - finish
            break;
        }

        if (equation == "*") {
            result = result * number_two;
        }
        else if (equation == "+") {
            result = result + number_two;
        }
        else if (equation == "-") {
            result = result - number_two;
        }
        else if (equation == "/") {
            if (number_two != 0) {
                result = result / number_two;
            }
            else {
                cout << "Error: division by zero" << endl;
                break;
            }
        }
        else {
            cout << "Error: " << equation << endl;
            break;
        }
    }

    // Print the final result after calculations
    cout << result << endl;
}



bool Divby0 = false;
extern double result;
extern bool Divby0;
extern string equation;
extern double number_two;
void ZRmod() {

    while (true) {
        if (!(cin >> equation >> number_two)) {
            // No more input or invalid input - finish
            break;
        }

        if (equation == "*") {
            result = result * number_two;
        }
        else if (equation == "+") {
            result = result + number_two;
        }
        else if (equation == "-") {
            result = result - number_two;
        }
        else if (equation == "/") {
            if (number_two != 0) {
                result = result / number_two;
            }
            else {
                cout << "Error: division by zero" << endl;
                Divby0 = true;
                break;

            }
        }
        else {
            cout << "Error: " << equation << endl;
            break;
        }
    }

    // Print the final result after calculations
    if (Divby0 != true) {
        cout << result << endl;
    }

}
