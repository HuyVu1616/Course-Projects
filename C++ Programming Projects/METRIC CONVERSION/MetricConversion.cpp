/*MetricConversion.cpp
Name: Huy Vu
ID: 1082787
*/

#include <iostream>
#include <cctype>
#include <iomanip>

char menuSelect();
using namespace std;

int main (int argc, char* argv[])
{
    double inches;
    double centimeters;
    char select;

    do {
        select = menuSelect();
        if (select == 'I')
        {
            cout << "Enter Inches: " ;
            cin >> inches;
            
            // Check for invalid input
            if (cin.fail()) {
                cin.clear(); // clear the fail state
                cin.ignore(10000, '\n'); // discard invalid input
                cerr << "Error: Input must be a valid number." << endl;
                continue;
            }
            try 
            {
                if (inches < 0)
                    throw 0;
                centimeters = inches * 2.54;
                cout << inches << "inches equals to " << setprecision(2) << centimeters  << " centimeters." << endl;
            }
            catch (int errID)
            {
                cerr << "Error: " << errID << endl;
                cerr << "Inches must be a positive number" << endl;
            }
        }
        else if (select == 'C') 
        {
            cout << "Enter Centimeters: ";
            cin >> centimeters;

            if (cin.fail()) {
                cin.clear(); // clear the fail state
                cin.ignore(10000, '\n'); // discard invalid input
                cerr << "Error: Input must be a valid number." << endl;
                continue;
            }
            try 
            {
                if (centimeters < 0)
                    throw 0;
                inches = centimeters / 2.54;
                cout << centimeters << " equals to "<< setprecision(2) << inches  << " inches." << endl;
            }
            catch (int errID)
            {
                cerr << "Error: " << errID << endl;
                cerr << "Centimeters must be a positive number" << endl;
            }
        }
    } while (select != 'Q');
    return 0;
}

char menuSelect() {
    char selection;
    do 
    {
        cout << endl;
        cout << "Enter I (inch to meter), C (Centimeter to Inch), or Q to quit: " << endl;
        cin >> selection;
        selection = toupper(selection);
    } while (selection != 'I' && selection != 'C' && selection != 'Q');
    return selection;
}