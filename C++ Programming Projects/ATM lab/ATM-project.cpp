// ATM.cpp : This file contains all of the code for the ATM simulato
//           Code for deposits needs to be completed
//

#include <iostream>
#include <iomanip>
#include "ATM.hpp"
#include "console_IO.hpp"
using namespace std;

int main()
{
    streamoff customerIndex;
    char anotherRequest = ' ';
    ATM customerTransaction;

    while (true) {  // infinite loop - typical for embedded systems
        cout << "\n\n===========================\n";
        cout <<     "== Welcome to Phony Bank ==\n";
        cout <<     "===========================\n\n";

        customerIndex = customerTransaction.searchForCustomer();
        do {
            if (customerIndex == -1) {
                return -1;  // can't open the customer file. Exit program
            }
            else if (customerIndex == -2) {
                cout << "Account number not found" << endl;
                continue;
            }
            else if (customerIndex == -3) {
                cout << "Incorrect PIN" << endl;
                continue;
            }
            else if (customerIndex == -4)  // the customer file was displayed
                continue;
            char checkingOrSavings = customerTransaction.selectAccount(customerIndex); // 'C' = checking, 'S' = savings, 'X' = cancel
            if (checkingOrSavings == 'X')
                break;  // done with this customer
            
            char transaction = customerTransaction.selectTransaction();
            switch (transaction) {
            case 'B':  // balance
                cout << showpoint << fixed << setprecision(2);
                cout << "$" << customerTransaction.getBalance(customerIndex, checkingOrSavings) << endl;
                break;
            case 'D':  // deposit
                customerTransaction.deposit(customerIndex, checkingOrSavings);
                break;
            case 'W':  // withdraw
                customerTransaction.withdraw(customerIndex, checkingOrSavings);
                break;
            case 'X':  // cancel
                break;
            }
            // Do you want another requst for the same customer?
            do { // get a 'Y' or 'N' response
                cout << "Do you want another transaction for the same customer? (Y/N)? ";
                anotherRequest = toupper(getChar());
            } while (anotherRequest != 'Y' && anotherRequest != 'N');
        } while (anotherRequest == 'Y');
    } // end of while (true)
    return 0;   // end of main( )
}