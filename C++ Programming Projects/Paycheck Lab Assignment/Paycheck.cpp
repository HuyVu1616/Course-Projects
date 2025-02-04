/*  C++ Paycheck.cpp : Defines entry points for the console app;ication.
    Huy Vu
    CIS054 C/C++ Programming
    Inputs: names, hours, taxRate
    Outputs: grossPay, taxes, netPay
*/

#include <iostream>     // Used for cin and cout
#include <iomanip>      // Used to set 2 digits past the Decimal            
using namespace std;

// define the constants
const double OVERTIME_RATE = 1.5;   // time and a half for overtime
const double TAX_RATE = 0.14;       // 0.14 is 14%

int main(int argc, char* argv[])
{
    // Declare the variables
    char name[100];
    double hours, payRate;
    double regHours, overtimeHours;
    double regPay, overtimePay;
    double grossPay, taxes, netPay;

    // INPUT: your name, hours and payRate
    cout << "Enter your name: ";            // prompt
    cin.getline(name, 100);                 // read up to 100 characters
    cout << "Enter the hours worked: ";     // prompt
    cin >> hours;                           // read hours from keyboard
    cout << "Enter the pay rate: ";         // prompt
    cin >> payRate;                         // read payRate from keyboard

    // PROCESS: compute the paycheck
    // separate the regular and overtime hours
    // compute regular, overtime and total paycheck
    if (hours <= 40.0)                      // less or equal to 40. No overtime
    {
        regHours = hours;                   // separate regHours and overtimeHours
        overtimeHours = 0.0;
    }
    else                                    // over 40. How much is overtime? 
    {
        regHours = 40.0;                    // regular pay for the first 40 hours 
        overtimeHours = hours - 40.0;       // anything over 40 hours
    }
    regPay = regHours*payRate;
    overtimePay = overtimeHours * payRate * OVERTIME_RATE;
    grossPay = regPay + overtimePay;
    taxes = grossPay * TAX_RATE;
    netPay = grossPay - taxes;

    // Output: welcome message, and paycheck with 2 digits past the decimal
    cout << endl << "Paycheck for " << name << endl;
    cout << setiosflags(ios::fixed | ios::showpoint);
    cout << "Your gross pay is $" << setprecision(2) << grossPay << endl;
    cout << "Your taxes are $" << setprecision(2) << taxes << endl;
    cout << "Your net pay is $" << setprecision(2) << netPay << endl;

    return 0;


}