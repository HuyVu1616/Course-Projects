// falafel.cpp 
// CIS-054 C/C++ Programming
// Huy Vu

#include <iostream>   // used for cout and cin
#include <iomanip>    // used to set digits past decimal
#include <cctype>     // used for toupper ( )
void displayMenu();   // function prototype
using namespace std;

const double PRICE_FALAFEL = 5.15;
const double PRICE_SODA    = 2.24;
const double PRICE_EXTRA   = 1.57;
const double TAX_RATE      = 0.087;

int main(int argc, char* argv[])
{
    double subtotal = 0.00;
    double price;
    char selection;
    int itemCount = 0;

    int falafelCount = 0;
    int sodaCount    = 0;
    int extraCount   = 0;

    double tax;
    double total;

    displayMenu();
    do
    {
        price = 0;
        cout << "Make your selection (FSXT): ";
        cin >> selection;
        switch (toupper(selection))
        {
        case 'F':
            price = PRICE_FALAFEL;
            itemCount++;
            falafelCount++;
            break;
        case 'S':
            price = PRICE_SODA;
            itemCount++;
            sodaCount++;
            break;
        case 'X':
            price = PRICE_EXTRA;
            extraCount++;
            itemCount++;
            break;
        case 'T':
            break;
        default:
            cout << "Illegal selection, try again." << endl;
        }
        subtotal += price;
        tax = subtotal * TAX_RATE;
        total = subtotal + tax;
    } while (selection != 'T' && selection != 't');

    cout << setiosflags(ios::fixed | ios::showpoint); // display past the decimal
    cout << setprecision(2);  // 2 digits past the decimal point
    cout << falafelCount << " falafels" << endl;
    cout << sodaCount << " sodas" << endl;
    cout << extraCount << " extras" << endl;
    cout <<"----------"<< endl;
    cout << itemCount << " total items" << endl;
    cout << "   Subtotal    $" << subtotal << endl;
    cout << "   Tax         $" << tax      << endl;
    cout << "   Total       $" << total    << endl;
    return 0;
}

void displayMenu()
{
    cout << setiosflags(ios::fixed | ios::showpoint); // display past the decimal
    cout << setprecision(2);  // 2 digits past the decimal point
    cout << endl;   // blank line before start of menu
    cout << "F = falafel  $" << PRICE_FALAFEL << endl;
    cout << "S = soda     $" << PRICE_SODA << endl;
    cout << "X = extras   $" << PRICE_EXTRA << endl;
    cout << "T = total" << endl;
}