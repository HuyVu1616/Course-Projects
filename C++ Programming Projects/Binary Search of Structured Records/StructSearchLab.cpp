//
// SearchingLab.cpp : Searches a data file a) by seqential search, then b) binary search
//   NOTE: The data file must be sorted for the binary search to be successful
//
//   IMPORTANT: The filename[ ] array below is showing the location of the phony.422 file on
//              my computer. You need to modify this line to point to the file on your computer
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

#define debug_messages 1

// define the max number of records in the file
const int LIST_LENGTH = 256;

// define the lengths of each character array
const int NAME_SIZE = 40;
const int NUMBER_SIZE = 13;
const int LINE_SIZE = 80;

// define the structure for the array of records
typedef struct S_REC
{
    char name[NAME_SIZE];
    char number[NUMBER_SIZE];
} PhoneRec;

int main(int argc, char *argv[])
{
    PhoneRec List[LIST_LENGTH]; // [length][width]
    char line[LINE_SIZE];       // line of text from the disk
    char filename[] = "/Users/Dell/Desktop/phony422.txt";
    char *ptr;
    int searchCounter = 0;

    /////////////////////////////////////////////////////
    /////// Read the file into the List[ ]  array ///////
    /////////////////////////////////////////////////////
    ifstream PhoneFile(filename);

    if (!PhoneFile)
    {
        cerr << "Unable to open " << filename << endl;
        return 1;
    }

    int listsize = 0;
    line[0] = 0;                        // clear the line buffer
    PhoneFile.getline(line, LINE_SIZE); // read the first line in the file
    while (!PhoneFile.eof() && listsize < LIST_LENGTH && line[0])
    {
        if (strlen(line) > 1)
        {
            // pick a version of strtok and strcpy that works with your compiler

            // VERSION-1
            // These 5 lines work for Microsoft Visual Studio. Comment them out if using Version-2
            char *nextToken = NULL;                            // used only by strtok_s
            ptr = strtok_s(line, ".", &nextToken);             // find name, separated by '.' character
            strcpy_s(List[listsize].name, NAME_SIZE, ptr);     // copy name to array, position listsize
            ptr = strtok_s(NULL, ".\r\n", &nextToken);         // find phone number
            strcpy_s(List[listsize].number, NUMBER_SIZE, ptr); // copy to array, position listsize

            // VERSION-2
            // Uncomment these 4 lines on a Mac using Xcode or other systems
            // ptr = strtok(line, ".");                 // find name, separated by '.' character
            // strcpy (List[listsize].name, ptr);       // copy name to array, position listsize
            // ptr = strtok(NULL, ".\r\n");             // find phone number
            // strcpy (List[listsize].number, ptr);     // copy to array, position listsize

            listsize++;
        }
        line[0] = 0;                        // clear the buffer
        PhoneFile.getline(line, LINE_SIZE); // read next line
    }

#if debug_messages == 1
    cout << "There are " << listsize << " lines in the file." << endl;
#endif

    /////////// request a search string, then find it //////////

    char searchString[80];
    char select;
    bool found = false;
    while (select != 'q')
    {
        cout << "Enter selection (p/n): ";
        cin >> select;
        cin.ignore();

        if (select == 'p')
        {
            cout << "Enter a phone number: ";
            cin.getline(searchString, 80);

            int index;
            for (index = 0; index < listsize; index++)
            {
                searchCounter++;
                if (strstr(List[index].number, searchString))
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                cout << "Customer name: " << List[index].name << endl;
                cout << searchCounter << " tests were made" << endl;
            }
            else
                cout << "Not found" << endl;
        }

        if (select == 'n')
        {
            cout << "Enter a name: ";
            cin.getline(searchString, 80);

            int index;
            for (index = 0; index < listsize; index++)
            {
                searchCounter++;
                if (strstr(List[index].name, searchString))
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                cout << "Customer's Number: " << List[index].number << endl;
                cout << searchCounter << " tests were made" << endl;
            }
            else
                cout << "Not found" << endl;
        }
    }
    ///////////////////////////////////////////////////
    //////////////// binary search ////////////////////
    ///////////////////////////////////////////////////
    searchCounter = 0;
    int ndex = 128;
    int lowerBound = 0;
    int upperBound = listsize - 1;
    int midPoint = 0;

    cout << "\n\n********** Starting the BINARY SEARCH **********\n";

    while (lowerBound <= upperBound)
    {
        searchCounter++;
        midPoint = (lowerBound + upperBound) / 2;

#if debug_messages == 1
        cout << searchCounter << " lowerBound = " << lowerBound << " midPoint=" << midPoint
             << " upperBound=" << upperBound << "  " << List[midPoint].name << endl;
#endif

        // IMPORTANT: Microsoft uses _stricmp  with the underscore as part of the function name.
        //   Some C/C++ compilers uses stricmp for string compare, ignore case
        //   other compilers use strcasecmp for string compare, ignore case.
        //   If you get a compiler error using _strcmpi, then try stricmp or strcasecmp
        //      until you are able to compile the program without an error on these lines

        if (_strcmpi(List[midPoint].number, searchString) < 0)
            lowerBound = midPoint + 1; // getting closer, cutoff the lower half
        else if (_strcmpi(List[midPoint].number, searchString) > 0)
            upperBound = midPoint - 1; // getting closer, cutoff the upper half
        else
        {
            found = true;
            break;
        }
    }
    if (found)
    { // found
        cout << "Customer name: " << List[midPoint].name << endl;
        cout << searchCounter << " tests were made" << endl;
    }
    else
        cout << "Not found in " << searchCounter << " tries" << endl
             << endl;

    return 0;
}
