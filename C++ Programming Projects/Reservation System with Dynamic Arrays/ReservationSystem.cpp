/*
ReservationSystem.cpp
Name and ID: Huy Vu - 1082787
Date: 11/16/2024

*/
#include <iostream>
#include <cctype>
using namespace std;

// Function declarations (prototypes)
char **CreateArrayOfSeats(int NumberOfRows, int seats);
void InitializeSeats(char **ArrayOfSeats, int NumberOfRows, int seats);
void DisplayArrayOfSeats(char **ArrayOfSeats, int NumberOfRows, int seats);
void MemoryCleanup(char **ArrayOfSeats, int NumberOfRows, int seats);

int main(int argc, char *argv[])
{
    char **ArrayOfSeats;
    int NumberOfRows;
    int NumberOfSeats;
    char rowSelection;  // 1 to max NumberOfRows, input from the user
    char seatSelection; // 'A' to max seats, input from the user, convert to a number
    int row;            // index into ArrayOfSeats, 0 to NumberOfRows-1
    int seat;           // index into ArrayOfSeats, 0 to seats-1

    // get the number of NumberOfRows and seats from the user
    cout << "Enter the number of NumberOfRows: ";
    cin >> NumberOfRows;
    cout << "Enter the number of seats on each row: ";
    cin >> NumberOfSeats;

    int totalSeats = NumberOfRows * NumberOfSeats;
    int takenSeats = 0;

    ArrayOfSeats = CreateArrayOfSeats(NumberOfRows, NumberOfSeats);
    InitializeSeats(ArrayOfSeats, NumberOfRows, NumberOfSeats);
    DisplayArrayOfSeats(ArrayOfSeats, NumberOfRows, NumberOfSeats);

    do
    {
        cout << "Seat Available: " << totalSeats - takenSeats;
        if (takenSeats == totalSeats)
        {
            cout << "All seats are taken!" << endl;
            break;
        }
        cout << endl
             << "Enter a seat selection" << endl
             << "  (example 5F -or- 00 to quit): ";
        cin >> rowSelection;  // get row from the user
        cin >> seatSelection; // get the seat from the user

        if (rowSelection == '0')
            continue; // skip the rest of the loop

        seatSelection = toupper(seatSelection); // convert to upper case
        row = rowSelection - '1';               // count from zero to work with the array
        seat = seatSelection - 'A';             // convert 'A' to 0, 'B' to 1, 'C' to 2, etc.

        if (row < 0 || row > rowSelection || seat < 0 || seat > seatSelection)
        {
            cout << "Invalid selection. Please try again!";
            continue;
        }
        if (ArrayOfSeats[row][seat] == '-')
        {
            cout << "Seat is taken. Please select another seat!" << endl;
        }

        else
        {
            ArrayOfSeats[row][seat] = '-';
            takenSeats++;
        }

        DisplayArrayOfSeats(ArrayOfSeats, NumberOfRows, NumberOfSeats);

    } while (rowSelection != '0');

    MemoryCleanup(ArrayOfSeats, NumberOfRows, NumberOfSeats); // return the memory

    return 0;
}

char **CreateArrayOfSeats(int NumberOfRows, int seats) // ** means pointer to pointers
{
    char **ArrayOfSeats;
    ArrayOfSeats = new char *[NumberOfRows]; // create array of pointers for NumberOfRows
    for (int r = 0; r < NumberOfRows; r++)
        ArrayOfSeats[r] = new char[seats]; // create an array of seats for each row
    return ArrayOfSeats;                   // return pointer to the array back to main program
}

void InitializeSeats(char **ArrayOfSeats, int NumberOfRows, int seats)
{
    for (int r = 0; r < NumberOfRows; r++) // initialize the data for each row
    {
        for (int s = 0; s < seats; s++)
            ArrayOfSeats[r][s] = 'A' + s; // put 'A' 'B' 'C' etc in each row
    }
}

void DisplayArrayOfSeats(char **ArrayOfSeats, int NumberOfRows, int NumberOfSeats)
{
    for (int r = 0; r < NumberOfRows; r++) // for each row
    {
        cout.width(2);
        cout << r + 1 << ' '; // Display row numbers starting from 1
        for (int s = 0; s < NumberOfSeats; s++)
            cout << ArrayOfSeats[r][s] << ' '; // Display info for each seat
        cout << endl;                          // new line after each row
    }
}

void MemoryCleanup(char **ArrayOfSeats, int NumberOfRows, int NumberOfSeats)
{
    for (int r = 0; r < NumberOfRows; r++)
        delete[] ArrayOfSeats[r]; // delete each row of seats individually
    delete[] ArrayOfSeats;        // delete the row array
}