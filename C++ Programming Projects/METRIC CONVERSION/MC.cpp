#include <iostream>
#include <cctype>
using namespace std;

char menuSelect();

int main(int argc, char* argv[]) {
    double inches;
    double centimeters;
    char select;

    do {
        select = menuSelect();
        if (select == 'I') {
            cout << "Enter Inches: ";
            cin >> inches;
            
            // Check for invalid input
            if (cin.fail()) {
                cin.clear(); // clear the fail state
                cin.ignore(10000, '\n'); // discard invalid input
                cerr << "Error: Input must be a valid number." << endl;
                continue;
            }

            try {
                if (inches < 0) {
                    throw 0; // Error for negative input
                }
                // Conversion should happen after the input is validated
                centimeters = inches * 2.54;
                cout << inches << " inches equals to " << centimeters << " centimeters." << endl;
            } catch (int errID) {
                if (errID == 0) {
                    cerr << "Error: Inches must be a positive number." << endl;
                } 
            }

        } else if (select == 'C') {
            cout << "Enter Centimeters: ";
            cin >> centimeters;

            // Check for invalid input
            if (cin.fail()) {
                cin.clear(); // clear the fail state
                cin.ignore(10000, '\n'); // discard invalid input
                cerr << "Error: Input must be a valid number." << endl;
                continue;
            }

            try {
                if (centimeters < 0) {
                    throw 0; // Error for negative input
                }
                
                // Conversion should happen after the input is validated
                inches = centimeters / 2.54;
                cout << centimeters << " centimeters equals to " << inches << " inches." << endl;
            } catch (int errID) {
                if (errID == 0) {
                    cerr << "Error: Centimeters must be a positive number." << endl;
                } 
            }
        }
    } while (select != 'Q');
    
    return 0;
}

char menuSelect() {
    char selection;
    do {
        cout << endl;
        cout << "Enter I (Inch to Centimeter), C (Centimeter to Inch), or Q to quit: " << endl;
        cin >> selection;
        selection = toupper(selection);
    } while (selection != 'I' && selection != 'C' && selection != 'Q');
    return selection;
}