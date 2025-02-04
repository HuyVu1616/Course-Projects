// MaxPlayers - Determines if there are not enough, too many
// or just right for the number of players on a team
// HUY VU
// CIS C/C++ Programming

#include <iostream>         // used by cin and cout

using namespace std;        

int selectTeamSize();       // function prototype

int main (int argc, char* argv[])
{
    int teamSize;
    int playersOnTeam;
    int morePlayersNeeded;
    int extraPlayers;

    // Display a title at the top of program's ouput

    cout << "Welcome to the team size selectior program:" << endl << endl;

    // Input the data
    // use the SelectTeamSize() function to select a sport and return
    // the number of players needed on a team for that sport

    teamSize = selectTeamSize();        // use function shown below
    cout << "There should be " << teamSize << " players on the team" << endl;

    cout << "How many players are currently on the team?";
    cin >> playersOnTeam;
    if (cin.fail()) {
        cout << "Illegal entry for team size" << endl;
        return 1;
    }

    // Process and output

    if (playersOnTeam < teamSize) {
        cout << "there are not enough players" << endl;
        morePlayersNeeded = teamSize - playersOnTeam;
        cout << morePlayersNeeded << "more players are needed" << endl << endl;
    }
    else if ( playersOnTeam > teamSize) {
        cout << "There are too many players" << endl;
        extraPlayers = playersOnTeam - teamSize;
        cout << extraPlayers << "players need to be eliminated" << endl << endl;
    }
    else {
        cout << "You have correct number of players" << endl << endl;
    }
    return 0;
}

// The selectTeamSize() functions asks the user to select  a sport and then
// returns the number of players on a team for that sport.
 int selectTeamSize()
{
    char teamSelection; // team selection entered at the keyboard 1-4
    int teamSize;       // numbers of players that should be on a team  - returned to main

    do {
        cout << "Select a professional sport" << endl
            << "1 - NFL Football" << endl
            << "2 - NBA Basketball" << endl
            << "3 - MLB Basseball" << endl
            << "4 - NHL Hockey" << endl
            << "Select (1-4): ";
        cin >> teamSelection;

        if (teamSelection == '1')
            teamSize = 53;          // NFL
        else if ( teamSelection == '2')
            teamSize = 13;          // NBA
        else if (teamSelection == '3')
            teamSize = 25;          // MLB
        else if  (teamSelection == '4')
            teamSize = 23;          // NHL
        else {
            cout << "Illegal selection - Try again" << endl << endl;
            teamSize = 0;           // Error flag
        }
    } while ( teamSize == 0);       // Loop until a valid selection is made

    return teamSize;                // to be used by main program
}
