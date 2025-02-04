/* C++ SentenceFormatting.cpp
CIS054 C/C++ Programming
Name: Huy Vu
Date: 9/22/2024
*/
#include <iostream>
#include <cctype>

using namespace std;

int main (int argc, char* argv[])
{
    char sentence[200];
    int i;
    cout << "Enter a sentence:" << endl;
    cin.getline(sentence, 200);
    
    for (i=0; sentence[i]; i++)
    {
        if (isspace(sentence[i]))
        sentence[i] = ' ';

            while (sentence[i] != '\0')
            {
            if (sentence[i] == ' ' && sentence[i+1] == ' ')
            for (int j=i; sentence[j]; j++)
            {
                sentence[j] = sentence[j+1];
            }
            else
            i++;
            }
            sentence[0] = toupper(sentence[0]);
                for (i+1; sentence[i]; i++)
                {
                sentence[i] = tolower(sentence[i]);
                }
    }
    cout << sentence << endl;
}
