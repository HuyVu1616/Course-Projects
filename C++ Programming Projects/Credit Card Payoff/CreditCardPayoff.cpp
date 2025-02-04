/* C++ CreditCardPayoff.cpp
CIS054 C/C++ Programming
Name: Huy Vu
Date: 9/22/2024
*/

#include <iostream>
#include <iomanip>
using namespace std;

const double YEARLY_INTEREST_RATE = 22.24 /100.0;
const double MONTHLY_INTEREST_RATE = YEARLY_INTEREST_RATE / 12;
const double CREDIT_LIMIT = 500.00;
const int MAX_MONTHS = 12;

int main()
{
    // Input values
    double balance = 240.75;
    double payment = 35.00;
    double charges = 60.00;
    
    // Computed values
    double interest;
    double newBalance;
    int month = 1;

    // Table column headings
    cout << fixed << showpoint;
    cout << setw(7) << "Month" << setw(9) << "Balance" << setw(10) << "interest" << setw(9) << "Payment" 
    << setw(9) << "Charges" << setw(12) << "New Balnce" << endl;

    do 
    {
        interest = balance * MONTHLY_INTEREST_RATE;
        newBalance = balance + interest + charges - payment;

        // Dispplay table values

        cout << setprecision(2);
        cout <<setw(7) << month << setw(9) << balance << setw(10) << interest << setw(9) << payment 
        << setw(9) << charges << setw(12) << newBalance << endl;

            month++;
            balance = newBalance;
    } while (balance >= 0.005 && balance <= CREDIT_LIMIT);
}
