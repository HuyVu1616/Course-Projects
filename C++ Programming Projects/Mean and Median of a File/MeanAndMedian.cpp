// MeanAndMedianOfDataFile.cpp
//
// This sample provides the first part of the code for computing the median but does not include the mean.
// It is your task to complete the code to compute the mean and median values.
//
#include <iostream>
#include <fstream>
#include <cstdlib>  // used by the exit() functiona
using namespace std;

int main(int argc, char* argv[])
{
    // variables to control the disk file
    ifstream infile;
    char filename[200];
    int  recordCount = 0;
    int  recordsToSkip = 0;
    // variables for fields of each record in the file
    int    AcctNo = 0;
    char   Name[100] = "";
    double AcctBal = 0.0;
    // varible used to determine the median
    double median = 0.0;
    
    cout << "Enter the name of the data file (Example:  /Users/Dell/Desktop/balances1.txt):  ";
    cin.getline(filename, 200);
    
    // ---- PART 1, Count the number of records in the file
    //      Determine the mean when you know the record count and the total of all balances
    infile.open(filename);
    if (infile.fail())
    {
        cerr << "Unable to open --" << filename << "--, first pass" << endl;
        exit(1);
    }
    while (!infile.eof())   // while not end of file
    {
        Name[0] = 0;        // initialize to 0 to test for empty records/
        infile >> AcctNo >> Name >> AcctBal;
        if (Name[0] != 0)   // ignore empty records
            recordCount++;
    }
    infile.close();
    cout << "There are " << recordCount << " records in " << filename << endl;
    
    
    // ---- PART 2, Determine the number of records to skip
    if (recordCount %2 == 1)
        recordsToSkip = recordCount/2;      // Odd number of records
    else
        recordsToSkip = recordCount/2 - 1;  // Even number of records
    
    // ---- PART 3, open the file, skip leading records, determine the median
    

	// - - - - - You need to complete the program
    infile.open(filename);
    if(infile.fail()){
        cerr << "Unable to open: " << filename << endl;
        exit(1);
    }
    while (recordsToSkip !=0){
        infile >> AcctNo >> Name >> AcctBal;
        recordsToSkip--;
    }
    infile >> AcctNo >> Name >> AcctBal;
    if (recordCount %2 == 1) 
    {
        median = AcctBal;
    }
    else
    {
        median = AcctBal;
        infile >> AcctNo >> Name >> AcctBal;
        median =(median + AcctBal)/2;
    }
    infile.close();
    // Display the results
    cout << "The median of " << filename << " is " << median << endl << endl;
    
	return 0;
}
