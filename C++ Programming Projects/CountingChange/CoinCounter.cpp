/*  C++ CoinCounter.cpp
    Huy Vu
    CIS054 C/C++ Programming
    Inputs: quarters, dimes, nickels, pennies
    Outputs: title message, total message
*/

#include <iostream>     // Used for cin and cout
#include <iomanip>      // Used to set 2 digits past the Decimal            
using namespace std;

// define the constants
const double QUARTER_VALUE = 0.25;
const double DIME_VALUE = 0.10;
const double NICKEL_VALUE = 0.05;
const double PENNY_VALUE = 0.01;

int main(int argc, char* argv[])
{
    double quarters;
    double dimes;
    double nickels;
    double pennies;
    double total;

    // Input:
    cout << "Welcome to Change Counting Program" << endl;
    cout << "Enter number of quaters: " << endl;
    cin >> quarters;
    cout << "Enter number of dimes: " << endl;
    cin >> dimes;
    cout << "Enter number of nickels: " << endl;
    cin >> nickels;
    cout << "Enter number of pennies: " << endl;
    cin >> pennies;

    total = quarters*QUARTER_VALUE + dimes*DIME_VALUE + nickels*NICKEL_VALUE + pennies*PENNY_VALUE;
    
    // Output:
    cout << "Your total is : $" << total << endl;

    return 0;
}