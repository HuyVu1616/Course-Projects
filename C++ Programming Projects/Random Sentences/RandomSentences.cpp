//  C++RandomSentences
//     concatenates one random string onto another string
//
//  Dan McElroy
//
#include <iostream>    // needed for cout
#include <cstdlib>     // needed for the random number generator
#include <ctime>       // needed to seed the random number generator
#include <cctype>      // needed for toupper()
#include <string>      // needed for C++ strings
using namespace std;

// create an array of nouns, determine how many nouns are in the array

const string article[] = {"the", "a", "one", "some", "any"};

const string adjective[] = { "brave", "orange", "fast", "slow", "smart"};

const string noun[] = {
  "desk", "chair", "envelope", "car", "train", "bus", "boat",
  "elephant", "dog", "cat", "moose", "rabbit"
};

const string verb[] = {"drove", "jumped", "ran", "walked", "skipped"};

const string reposition[] = {"to", "from", "over", "under","on"}; 

int articleCount = sizeof(article)/sizeof(string);
int nounCount = sizeof(noun)/sizeof(string);
int adjectiveCount = sizeof(adjective)/sizeof(string);
int verbCount = sizeof(verb)/sizeof(string);


int main(int argc, const char * argv[])
{
    // declare the variables
    string sentence;        // C++ string object
    int selection;

    srand( (unsigned int)time(0) );    // seed the random number generator
    
    for (int i=0; i<20; i++) {          // create and display 5 sentences
        // put in a noun
        selection = rand()%articleCount;
        sentence = article[selection];
        sentence += " ";

        selection = rand()%adjectiveCount;
        sentence = adjective[selection];
        sentence += " ";

        selection = rand()%nounCount;  // pick a random noun
        sentence += noun[selection];    // use = to place the 1st word in the sentence
        sentence += " ";               // use += to add a space after each word

        selection = rand()%verbCount;
        sentence += verb[selection];
        sentence += " ";
        
        selection = rand()%nounCount;  // pick another random noun
        sentence += noun[selection];   // use += to add another word to sentence
        sentence += ".";               // use += to add a period at the end
        
        sentence[0] = toupper(sentence[0]);     // make 1st char capital letter
        cout << sentence << endl;               // display the sentence
    }
    return 0;
}