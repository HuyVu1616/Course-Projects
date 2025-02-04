#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////    
//// The following methods read from the keyboard and 
////   verify that valid data was entered
////////////////////////////////////////////////////////////    
// char getChar()
//  reads a line of text from standard input (keyboard)
//  returns the first character that was input
//  the rest of the line is discarded
char getChar() {
    char buff[100];
    cin.getline(buff, 100);
    return(buff[0]);
}

////////////////////////////////////////////////////////////    
// int getInt()
//  reads an integer from standard input (keyboard)
//  returns the first integer that was input
//  displays an error message and tries again if a non-integer is input
int getInt() {
    int result;
    bool tryAgain;
    do {
        tryAgain = false;
        try {
            char buff[100];
            cin.getline(buff, 100);
            result = atoi(buff);
            if (cin.fail())
                throw 1; // different values for the throw to display different conditions in the catch
        }
        catch (...) {
            cout << "*** Illegal entry. Enter an integer. Try again" << endl << "? ";
            cin.clear(); // clear the input buffer
            cin.ignore(1000, '\n'); // and ignore anything else before a new cin
            tryAgain = true;
        }
    } while (tryAgain);
    return result;
}

////////////////////////////////////////////////////////////    
// double getDouble()
//  reads a real number from standard input (keyboard)
//  returns the first double that was input
//  displays an error message and tries again if an error is detected
double getDouble() {
    double result;
    bool tryAgain;

    do {
        tryAgain = false;
        try {
            char buff[100];
            cin.getline(buff, 100);
            result = atof(buff);
            if (cin.fail())
                throw 1; // different values for the throw to display different conditions in the catch
        }
        catch (...) {
            cout << "*** Illegal entry. Enter an number. Try again" << endl << "? ";
            tryAgain = true;
        }
    } while (tryAgain);
    return result;
}