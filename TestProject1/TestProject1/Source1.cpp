#include <iostream>
using namespace std;
#include "Specific.cpp"//--------------------------------------------------------------------->>>>
#include "V2calc.cpp"
#include <fstream>
#include <string>
#include "authorize.cpp"
#include <chrono>
#include <ctime>
#include <iomanip> 
#include <sstream>

/*
HOW TO USE:
Step One: go to the thing that says STDIN or scroll all the way up and look at the arrow
then click it so you can type.
Step Two: type in
v1, a space, or "none" for a normal calculator eg(12 + 1 + * 501345).
V2 for a calculator that needs specifics (2-3 numbers dependant on what u want).
VarX for solving things like this "12x = 15" but typed in the STDIN as "12 x = 15".
PriceI (price increase in dollars new price then percent).
PriceD (price decrease in dollars original price then percent).
PriceI% (price increase as percent original then new).
PriceD% (price decrease as percent original then new).
grade  correct (space) out of blank.
Chart(grid) = chart number to other number.

/help for simple comands

Tell me what else I should add in the video game sharing google classroom or in person... no games

UPDATE LOG:

MAR 9, 2026
Added passwords for beta testing w/ possibility for txt file input.

MAR 3, 2026
Type /help in the STDIN for how to type simple equations. Code simplifacation and doubles
removed if statements.

MAR 2, 2026
Now you can just type out equations like 5 + 5 or 2 * 2 by themselves type it out like this 5 + 5
with those spaces or else it wont work but everything else is the same.
*/

// Returns Central Time (Illinois) in 12-hour HH:MM AM/PM format, approximate DST adjustment


int main() {
    auto start = std::chrono::high_resolution_clock::now();
    // Print Illinois time immediately on program start
    cout << "Program Executed at: " << getIllinoisTime12h() << " IL TIME\n\n";

    Authorize();
    if (authenticated == false) {
        return 0;
    }
    // Continue with the rest of your program...


    cin >> specific;



    if (parseSpecInt()) {
        number_two = number;
        saverspec = false;
        result = number;
        specificY = "none";
        ZRmod();

    }



    if (specific == "/help") {
        cout << "----simple functions----\nType the first number (space) + for addition - for\nsubtration / for division and * for multiplucation (space) 2nd \nnumber etc.\n";
        cout << "----v2----\nliterally just v2 then 2 - 3 digits\n";
        cout << "----grades----\ntype grades then the number of quetions you got correct then a \nspace and then how many quetions there were.\n";
        cout << "\n----More info----\n";
        cout << "There is more included in the code if you look at the instructions\nthis was to cover simple functions.";
    }


    specificf();
    if (specific == "v2") {
        v2_calc();
    }
    else if (specific == "VarX") {
        Varieable();
    }
    else if (specific == "PriceI" || specific == "PriceD" || specific == "PriceI%" || specific == "PriceD%") {
        PriceI_D();
    }
    else if (specific == "none" || specific == " " || specific == "v1" || specificY == "none") {
        specificf();
    }
    else if (specific == "chart") {
        Chart();
    }
    else if (specific == "%Is" || specific == "PO") {
        PIO();
    }
    else if (specific != "/help") {
        cout << "Error please try again.";
        return 0;
    }
    else {
        cout << "Try using this comand in the STDIN: /help\n";
    }





    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "\nTime taken to execute: " << duration.count() << " ms\n";

    return 0;
}
