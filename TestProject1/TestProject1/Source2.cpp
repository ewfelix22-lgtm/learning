#include <iostream>
#include "solver.cpp"
using namespace std;
#include <sstream>
#include <random>
// sayHelloFromNewFile1();
int repeater = 1;
string specific;
double number;
double number2;
double numd;
double numd2;
string Planet;
string VarieableX;
string VarieableY;
string Equalls;
int increment = 0;
int save = 2;
string specificY;
string multistep;
double maxVal;
double randomNumber;
double randomNumber2;
#include <iostream>
bool alternator = false;
void RandNumber() {
    // your variable max value
    cin >> number >> Equalls >> multistep >> save;
    maxVal = number;
    std::random_device rd;  // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, maxVal); // define the range
    if (alternator == false) {
        randomNumber = distr(gen);
    }
}



bool saverspec = true;
// Returns true if the global specific string is an int, and sets number accordingly
bool parseSpecInt() {
    stringstream ss(specific);
    int val;
    if (ss >> val && ss.eof()) {
        number = val;   // 'number' is declared in Specific.cpp
        saverspec = false;
        return true;
    }
    return false;
}

void PIO() {
    if (specific == "PO") {
        cin >> number >> number2;

        cout << number << " is ";
        numd = number * 100;
        cout << numd / number2 << "% " << "of " << number2;
    }
}





void Chart() {
    cin >> number >> Equalls >> number2;
    save = number2;

    if (Equalls == "*") {
        increment = 1;
    }






    while (number != 0) {

        do {
            if (number2 == 0 && number != 0) {
                cout << "\n";
                number2 = save;
            }
        } while (number2 == 0 && number != 0);
        while (number2 != 0) {
            cout << increment << " ";
            if (increment <= 9) {
                cout << " ";
            }
            if (Equalls == "+") {
                increment++;
            }
            number2--;
        }

        number--;
    }

}

void Varieable() {
    if (specific == "VarX") {
        cin >> numd >> VarieableX >> Equalls >> numd2;
        result = numd2 / numd;
        cout << "X = " << result;




    }





}



void PriceI_D() {
    if (specific == "PriceI" || specific == "PriceD") {
        cin >> numd >> numd2;
        result = numd - numd2;
        cout << "$" << result;
    }
    else if (specific == "PriceI%" || specific == "PriceD%") {
        double Z = numd;
        double Y = numd2;
        result = Y - Z;
        cout << result / numd << "%";
    }


}


void PlanetPE() {
    if (Planet == "Earth") {
        result = numd * numd2;
        cout << result * 9.807;
    }
    else if (Planet == "Mars") {
        result = numd * numd2;
        cout << result * 3.73;
    }
    else if (Planet == "Saturn") {
        result = numd * numd2;
        cout << result * 10.44;
    }
    else if (Planet == "Jupiter") {
        result = numd * numd2;
        cout << result * 24.79;
    }
    else if (Planet == "Venus") {
        result = numd * numd2;
        cout << result * 8.87;
    }
    else if (Planet == "Uranus") {
        result = numd * numd2;
        cout << result * 8.69;
    }
    else if (Planet == "Neptune") {
        result = numd * numd2;
        cout << result * 11.15;
    }
    else if (Planet == "Mercury") {
        result = numd * numd2;
        cout << result * 3.7;
    }
    else {
        result = numd * numd2;
        cout << result * 9.807;
    }
}









void specificf() {

    if (specific == "none" || specific == " " || specific == "v1") {

        ZR();  // Call the general calculator
        return;
    }
    else if (specific == "grade") {
        cin >> numd >> numd2;
        result = numd / numd2;
        cout << result * 100 << "%";
    }
    else if (specific == "KE") {
        cin >> numd >> numd2;
        result = numd * numd2 * numd2;
        cout << result / 2 << " Joules";
    }
    else if (specific == "GPE") {
        string Planet;
        cin >> Planet;
        cin >> numd >> numd2;
        PlanetPE();
    }
}
void questionGen() {

    if (multistep == "true") {
        cin >> save;
    }
    while (true) {

        RandNumber();
        alternator = true;

        save--;
        if (save > 2) {
            cout << randomNumber << Equalls;
            RandNumber();
        }
        if (save == 2) {
            cout << Equalls << randomNumber;
            RandNumber();
        }

        if (save == 0) {
            break;
        }


    }


}
