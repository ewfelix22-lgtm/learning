// calctest.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
string number;
double result;
string equation;
double number_two;
bool decider = true;

bool repeater() {
    
    if (number == "exit") {
        decider = false;
        return false;
        
    }
    else {
        return true;
    }
}


bool parseSpecInt() {
    stringstream ss(number);
    int val;
    if (ss >> val && ss.eof()) {
        result = val;   // 'number' is declared in Specific.cpp
        
        return true;
    }
    // try parsing as double
    try {
        size_t idx;
        double d = stod(number, &idx);
        if (idx == number.size()) {
            result = d;
            return true;
        }
    } catch (...) {
        // fall through
    }
    return false;
}








    int main() {
       
        string safety = "none";
        while (true) {
            if (!(cin >> number)) {
                // no more input
                return 0;
            }
            
             if (!repeater()) {
                return 0;
            }
             else if (number != "none") {
                
                // parse the first token (number)
                parseSpecInt();

                // read the rest of the current input line only, so we process one user input at a time
                string restOfLine;
                getline(cin, restOfLine); // reads until end of line

                if (!restOfLine.empty()) {
                    stringstream ss(restOfLine);
                    // parse operator and operand pairs from the rest of this line only
                    while (ss >> equation >> number_two) {
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
                    }
                }
                
                // Print the final result once for this user input (line)
                cout << result << "\n";
            }
             
        }
    
}
    /*
        Run program: Ctrl + F5 or Debug > Start Without Debugging menu
        Debug program: F5 or Debug > Start Debugging menu

        Tips for Getting Started:
          1. Use the Solution Explorer window to add/manage files
          2. Use the Team Explorer window to connect to source control
          3. Use the Output window to see build output and other messages
          4. Use the Error List window to see build errors
          5. Go to Project > Add New Item to add/manage files
        */