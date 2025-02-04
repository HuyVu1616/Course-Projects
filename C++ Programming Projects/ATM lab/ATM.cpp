//  ATM.cpp
//      displayFile()
//      searchForCustomer()
//      selectTransaction()
//      getBalance(streamoff, char)
//      deposit(streamoff, char)
//      withdraw(streamoff, char)

#include "ATM.hpp"
#include "console_IO.hpp"
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

////////////////////////////////////////////////////////////
// searchForCustomer()
//    return:  
//      >= 0 index into the file for the selected customer
//      -1 = unable to open customer file
//      -2 = customer not found in the fileIN
//      -3 = PIN does not match customer selection
//      -4 = customer file displayed to stdout
streamoff ATM::searchForCustomer() {
    int accountNo;
    int pin = 0;
    streamoff customerIndex = 0;      // -2=customer not found,  -3=PIN does not match
    ATM customer;                   // customer record (acctNo, PIN, chk, sav)

    cout << "Select a customer account number," << endl;
    cout << "[Enter] key to  display the customer data file" << endl;
    cout << "Account? ";
    accountNo = getInt();

    if (accountNo == 0) { // display file
        displayFile();
        return -4;  // entire customer file was displayed
    }
    if (accountNo >= 0) {
        cout << "Enter PIN? ";
        pin = getInt();
    }

    // open the customer data file
    ifstream ATM_file(ATMfilename, ios::binary);
    if (ATM_file.fail()) {
        cout << "Unable to open ATMaccounts " << endl;
        return -1;
    }
    ATM_file.read((char*)&customer, sizeof(customer));  // read first record   
    for (int i = 0; !ATM_file.eof(); i++) {
        if (accountNo == customer.getAcctNo()) { // found the customer in the file
            if (pin == customer.getPIN()) customerIndex = i;  // customer an PIN match
            else  customerIndex = -3; // PIN does not match return code
            break;  // customer and PIN match the request. Exit loop
        }
        ATM_file.read((char*)&customer, sizeof(customer));  // next customer
    }
    if (ATM_file.eof())   // reached EOF and didn't find the customer
        customerIndex = -2;  // customer not found
    ATM_file.close();

    if (customerIndex >= 0) {  // customer has been found. Display balances
        cout << fixed << showpoint << setprecision(2);
        cout << endl << "Checking $" << customer.getChecking()
            << "  Savings $" << customer.getSavings() << endl << endl;
    }
    return customerIndex;
}

////////////////////////////////////////////////////////////
// displayFile()
//   Displays all of the customer records in the file
//     return:  
//      0 = success
//     -1 = error displaying file
int ATM::displayFile() {
    ifstream ATM_file(ATMfilename, ios::binary);
    if (ATM_file.fail()) {
        cout << "Unable to open ATMaccounts " << endl;
        return -1;
    }
    ATM customer;    // customer record (acctNo, PIN, chk, sav)
    // display header information
    cout << fixed << showpoint << setprecision(2);  // format the output
    cout << setw(-7) << " Acct #" << "     "
        << setw(-4) << "PIN" << "   "
        << setw(-8) << "Checking" << "    "
        << setw(-8) << "Savings" << endl;

    ATM_file.read((char*)&customer, sizeof(customer));  // read first customer
    for (int i = 0; !ATM_file.eof(); i++) {
        cout << setw(7) << customer.getAcctNo() << "    "
            << setw(4) << customer.getPIN() << "   "
            << setw(8) << customer.getChecking() << "   "
            << setw(8) << customer.getSavings() << endl;
        ATM_file.read((char*)&customer, sizeof(customer));  // read next customer
    }
    ATM_file.close();
    return 0;
}

////////////////////////////////////////////////////////////
// selectAccount()
//    return:  'C  or  'S'   for checking or savings
char ATM::selectAccount(streamoff customerIndex) {
    cout << "Select account:" << endl;
    cout << "  C = checking" << endl;
    cout << "  S = savings" << endl;
    cout << "  X = cancel" << endl;

    char accountType = ' ';  // C=checking,  S=savings

    do {
        cout << "? ";
        accountType = toupper(getChar());
        if (accountType == 'C' || accountType == 'S' || accountType == 'X')
            break; // legal selection
        cout << "  Illegal selection. Try again." << endl;
    } while (accountType != 'C' && accountType != 'S' && accountType != 'X');
    return accountType;
}

////////////////////////////////////////////////////////////
// getBalance(int customerIndex, char accountType)
//    where:
//      customerIndex = customer number in the file
//      accountType     'C'=checking,  'S'=savings
//    return:  
//       of either customer's checking or savings account
double ATM::getBalance(streamoff customerIndex, char accountType) {
    double balance = 0.0;
    // search the file for the customer number
    ifstream ATM_file(ATMfilename, ios::binary);
    if (ATM_file.fail()) {
        cout << "Unable to open ATMaccounts " << endl;
        return balance;
    }
    ATM customer;    // customer record (acctNo, PIN, chk, sav)
    // seek to the selected customer
    streamoff customerPositionInFile = customerIndex * ATM::ATMsize;
    ATM_file.seekg(customerPositionInFile, ATM_file.beg);
    ATM_file.read((char*)&customer, sizeof(customer));
    if (accountType == 'C')
        balance = customer.getChecking();
    else if (accountType == 'S')
        balance = customer.getSavings();
    ATM_file.close();
    return balance;
}

////////////////////////////////////////////////////////////
// char selectTransaction()
//    return:  'B', 'D', 'W' or 'X'
char ATM::selectTransaction() { // D=deposit  W=withdraw  X=cancel
    cout << "Select transaction:" << endl;
    cout << "  B = balance" << endl;
    cout << "  D = deposit" << endl;
    cout << "  W = withdraw" << endl;
    cout << "  X = cancel" << endl;

    char transactionType = ' ';
    do {
        transactionType = toupper(getChar());
        if (transactionType == 'B' || transactionType == 'D' || transactionType == 'W' || transactionType == 'X')
            break; // legal selection
        cout << "  Illegal selection. Try again." << endl;
    } while (transactionType != 'B' && transactionType != 'D' && transactionType != 'W' && transactionType != 'X');
    return transactionType;
}

////////////////////////////////////////////////////////////
// void deposit(int customerIndex, char accountType)
//    where:
//      customerIndex = customer within the file
//      accountType:  'C'=checking   'S'=savings
//    The function requests the amount to deposit, then
//      validates that the amount is greater than zero
//      reads the customer record and adds the deposit
//    ` updates the customer data file
void ATM::deposit(streamoff customerIndex, char accountType) {
    double newBalance = 0.0;

    cout << "Enter the amount of the deposit: ";
    double depositAmount = getDouble();  // check for > 0 after getting current balance
    if (depositAmount <= 0) {
        cout << "Deposit must be greater than zero" << endl << endl;
        return;
    }
    // open in binary mode for both reading and writing
    fstream ATM_file(ATMfilename, ios::binary | ios::in | ios::out);
    if (ATM_file.fail()) {
        cout << "Unable to open ATMaccounts data file" << endl;
        return;
    }
    ATM currentCustomer;
    // seek to the selected customer from beginning of the file and update the selected balance
    streamoff customerPositionInFile = customerIndex * ATM::ATMsize;
    ATM_file.seekg(customerPositionInFile, ATM_file.beg);
    ATM_file.read((char*)&currentCustomer, sizeof(ATM));
    if (accountType == 'C') { // add the deposit to the customer's checking
        newBalance = currentCustomer.getChecking() + depositAmount;
        currentCustomer.setChecking(newBalance);
    }
    else if (accountType == 'S') { // add the deposit to the customer's savings
        newBalance = currentCustomer.getSavings() + depositAmount;
        currentCustomer.setSavings(newBalance);
    }

    // seek back to the same record and write the updated record back to disk
    ATM_file.seekg(customerPositionInFile, ATM_file.beg);
    ATM_file.write((char*)&currentCustomer, sizeof(ATM));

    // close the file
    ATM_file.close();

    // display the updated balance
    cout << fixed << showpoint << setprecision(2);  // display 2 digits past the decimal
    cout << "Your balance is $" << newBalance << endl;
}

///////////////////////////////////////////////////////////
// void withdraw(int customerIndex, char accountType)
//    where:
//      customerIndex = customer within the file
//      accountType:  'C'=checking   'S'=savings
//    The function requests the amount to withdraw, then
//      validates that the amount is an even multiple of $20.00
//      maximum withdrawal is $500.00
//      reads the customer record and validates sufficient funds
//      deducts the deposit and updates the customer data file
void ATM::withdraw(streamoff customerIndex, char accountType) {
    double withdrawAmount;
    double newBalance = 0.0;

    cout << "Enter the amount of the withdrawal in increments of $20 up to $500: ";
    withdrawAmount = getDouble();  // check for > 0 after getting current balance

    // compute amount of withdrawal in pennies used to check for increments of $20.00
    int intWithdrawX100 = (int)(withdrawAmount * 100);  // convert to pennies

    if (withdrawAmount <= 0.00)
        cout << "Withdrawal must be greater than zero" << endl << endl;
    else if (withdrawAmount > 500.00)
        cout << "Withdrawal must not exceed $500.00" << endl << endl;
    else if (intWithdrawX100 % 2000 != 0)  // 2000 = $20 in pennies, 
        cout << "Withdrawal must be in increments of $20.00" << endl << endl;
    else // proceed with withdrawal
    {
        // open in binary mode for both reading and writing
        fstream ATM_file(ATMfilename, ios::binary | ios::in | ios::out);
        if (ATM_file.fail()) {
            cout << "Unable to open ATMaccounts data file" << endl;
            return;
        }
        ATM currentCustomer;
        // seek to the selected customer from beginning of the file and update the selected balance
        streamoff customerPositionInFile = customerIndex * ATM::ATMsize;
        ATM_file.seekg(customerPositionInFile, ATM_file.beg);
        ATM_file.read((char*)&currentCustomer, sizeof(ATM));
        if (accountType == 'C') {   // update the customer's checking balance
            newBalance = currentCustomer.getChecking() - withdrawAmount;
            currentCustomer.setChecking(newBalance);
        }
        else if (accountType == 'S') { // update customer's savings balance
            newBalance = currentCustomer.getSavings() - withdrawAmount;
            currentCustomer.setSavings(newBalance);
        }
        // seek back to the same record and write the updated record back to disk
        ATM_file.seekg(customerPositionInFile, ATM_file.beg);
        ATM_file.write((char*)&currentCustomer, sizeof(ATM));

        ATM_file.close(); // close the file

        // display the updated balance
        cout << fixed << showpoint << setprecision(2);  // display 2 digits past the decimal
        cout << "Your balance is $" << newBalance << endl;
    } // end of a processed withdrawal
}
