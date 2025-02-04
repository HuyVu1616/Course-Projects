/*
RollDice.cpp
Name: Huy Vu
*/

#include <iostream>
#include <cstdlib>  // needed by srand() and srand()
#include <ctime>    // needed for the time() function

using namespace std;

// function prototypes
int roll();
int roll2Dice();

int main(int argc, char* argv[]) {
    int count2, count3, count4, count5, count6, count7, count8, count9, count10, count11, count12 = 0;
    for (int i = 1; i <=1000; i++){
        roll2Dice();
        switch (roll2Dice()){
            case 2:
            count2++ ;
            break;

            case 3:
            count3++ ;
            break;

            case 4:
            count4++ ;
            break;

            case 5:
            count5++ ;
            break;

            case 6:
            count6++ ;
            break;

            case 7:
            count7++ ;
            break;

            case 8:
            count8++ ;
            break;

            case 9:
            count9++ ;
            break;

            case 10:
            count10++ ;
            break;

            case 11:
            count11++ ;
            break;
            
            case 12:
            count12++ ;
            break;
        }          
    }
    cout << endl;
    cout << "2 = " << count2 << endl;
    cout << "3 = " << count3 << endl;
    cout << "4 = " << count4 << endl;
    cout << "5 = " << count5 << endl;
    cout << "6 = " << count6 << endl;
    cout << "7 = " << count7 << endl;
    cout << "8 = " << count8 << endl;
    cout << "9 = " << count9 << endl;
    cout << "10 = " << count10 << endl;
    cout << "11 = " << count11 << endl;
    cout << "12 = " << count12 << endl;
}

int roll() {
    static bool randomInitialized = false;
    if (!randomInitialized) {
        srand ( (unsigned int)time(NULL) );     // initialize the random number generator
        randomInitialized = true;               // dont do it again 
    }
    return (rand() % 6 ) + 1;
}
int roll2Dice () {
    int firstRoll = roll();
    int secondRoll = roll();
    int sum = firstRoll + secondRoll;
    return sum;
}