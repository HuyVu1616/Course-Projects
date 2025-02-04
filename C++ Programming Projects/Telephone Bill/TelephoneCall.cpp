/*  C++ TelephoneCall.cpp
    Huy Vu
    CIS054 C/C++ Programming
*/

#include <iostream>
#include <cstring>
using namespace std;

int main (int argc, char* argv[]) 
{
    // List of variables and constants
    const double WEEKEND_RATE = 0.15;   // $0.15 / minute
    const double EVENING_RATE = 0.25;   // $0.25 / minute
    const double DAY_RATE = 0.40;       // $0.40 / minute
    char day1;      
    char day2;
    int hour;
    char separator;
    int minute;
    int LengthOfCall;

    // used internally by the program
    char again;                 // loop control
    int TimeStarted;            // time in 24h clock, 6pm = 1800
    double billingRate;         // determined by day and time of call
    double CostOfCall;          // computed and displayed

    do 
    {
        // input the day of the week
        cout << "Enter the day ( Mo Tu We Th Fr Sa Su): ";
        cin >> day1 >> day2;    // input 2 characters
        day1 = toupper(day1);
        day2 = toupper(day2);

        // input the time the call was started
        cout << "Enter the time started (ex: 14:35): ";
        cin >> hour >> separator >> minute;     // input time
        TimeStarted = hour*100 + minute;

        // Input the length of call
        cout << "Enter the length of call in minutes: ";
        cin >> LengthOfCall;

        // Process - determine billingRate, then CostOfAll
        if (day1 == 'S' && day2 == 'A' )
            billingRate = WEEKEND_RATE;
        else if ( day1 == 'S' && day2== 'U')
            billingRate = WEEKEND_RATE;
        else 
        {
            if (TimeStarted >= 800 && TimeStarted <= 1800)
            billingRate = DAY_RATE;
            else
            billingRate = EVENING_RATE;
        }
        CostOfCall = LengthOfCall * billingRate;

        // output
        cout << "Your call lasted: " << LengthOfCall << " minutes." << endl;
        cout << "the cost of your call is $" << CostOfCall << endl;

        // loop control 
        cout << "Another call (Y/N)? ";
        cin >> again;
        again = toupper (again);
    } while (again == 'Y');
    return 0;
}   // end of main