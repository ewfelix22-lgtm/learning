#include <iostream>
using namespace std;

// Follow the steps below to use this file

// 1. In main file add the following include 
// #include "NewFile1.cpp"

// 2. Add the following in the code
// sayHelloFromNewFile1();
void v2_calc() {
    cout << "What number would you like info on and what is the range of one to x \n" << "also if you want to use a specific thing type yes then what\n";
    int number, range, height = 0;
    cout << "Enter number, range and height:\n";
    if (!(cin >> number >> range >> height)) {
        cin.clear();
        // If height is missing, set height to 0
        height = 0;
    }

    int leghth = number;
    int width = range;
    int rd = number * 2;
    int cd = number;
    double dleghth = leghth;
    double dheight = height;
    double dwidth = width;
    double area_thn = dleghth * dheight / 2;
    double area_trn = dleghth * dwidth / 2;


    for (int d = range; d >= 0; d--) {
        if (d == range) {
            cout << "-----------addition-----------\n";
        }
        cout << number + d << "\n";
    }

    cout << "-----------subtraction-----------\n";
    for (int s = range; s >= 0; s--) {
        cout << number - s << "\n";
    }
    for (int i = range; i >= 0; i--) {
        if (i == range) {
            cout << "-----------multiplication-----------\n";
        }
        cout << number * i << "\n";
    }

    cout << "-----------division-----------\n";
    for (int j = range; j > 0; j--) {  // avoid dividing by zero
        cout << static_cast<double>(number) / j << "\n";
    }

    cout << "-----------circumfrence(radius)-----------\n";
    cout << rd * 3.14 << "\n";



    cout << "-----------circumfrence(diamiter)-----------\n";

    cout << cd * 3.14 << "\n";



    cout << "-----------Area of quaderateral(2d)-----------\n";


    cout << leghth * width << "\n";

    if (height > 0) {
        cout << "-----------Area of quaderateral(3d)-----------\n";
        cout << leghth * width * height << " squared\n";





        cout << "-----------triangle(height & number)-----------\n";
        cout << area_thn << "\n";
        cout << "-----------triangle(range & number)-----------\n";
        cout << area_trn << "\n";
    }
    cout << "-----------triangle(range & number)-----------\n";
    cout << area_trn << "\n";
}
