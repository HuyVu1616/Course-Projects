// Program Name: TicTacToe.cpp
// Programmer:   Huy Vu
// Class:        CIS054 C/C++ Programming


#include <iostream> // needed for cin and cout
#include <cstdlib>  // needed by srand() and srand()
#include <ctime>    // needed for the time() function
using namespace std;

// function prototypes
void displayTicTacToe(char board[3][3]);
char checkForWinningGame(char board[3][3]);

int main(int argc, char* argv[])
{
    char board[3][3] = {    // index for positions in the array
        {'1', '2', '3'},        //  [0][0]  [0][1]  [0][2]
        {'4', '5', '6'},        //  [1][0]  [1][1]  [1][2]
        {'7', '8', '9'}         //  [2][0]  [2][1]  [2][2]
    };
    
    int  squareCounter = 0; // count how many squares are used
    char gameWinner = '-';  // winner of the game ('X' or 'O')
    char inputCharacter;    // input from the user (should be '1' to '9')
    int  choice;            // input converted to integer 0 to 8 (start from 0)
    char player;            // current player, set to either an 'X' or an 'O'
    
    // select the starting player
    srand( (unsigned int)time(NULL)); // seed the random number generator
    if ( rand() % 2 == 1)
        player = 'X';
    else
        player = 'O';
    
    // starting instructions
    cout << "Enter a 1 though 9  to select a square." << endl;
    
    // Ask for a 1-9 until all squares are filled or the game has been won
    while (squareCounter < 9 && gameWinner != 'X' && gameWinner != 'O')
    {
        cout << "--------------------------------" << endl;;
        displayTicTacToe(board);
        cout << "Player " << player << ", enter a number (1-9): ";
        cin  >> inputCharacter;
        
        // Arrays start counting from index 0
        // convert inputCharacter from ASCII ('1' to '9') to integer (0 to 8)
        // to select the row and column index for the 3x3 array
        choice = inputCharacter - '1'; // now the inputs are 0,1,2,3,4,5,6,7,8
        int row = choice / 3; // row will be 0 (for 0,1,2), 1 (for 3,4,5), 2 for (6,7,8)
        int col = choice % 3; // col will be 0 (for 0,3,6), 1 (for 1,4,7), 2 for (2,5,8)
        
        if (choice < 0 || choice > 8)   // see if the input is below 1 or greater than 0
            cout << "Illegal value, try again" << endl;
        else if (board[row][col]=='X' || board[row][col]=='O')
            cout << "This space has already been used, try again" << endl;
        else
        {
            board[row][col] = player;   // put in an 'X' or an 'O'
            squareCounter++;            // count the number of squares completed
            // select the next player
            if (player=='X')
                player = 'O';           // switch from 'X' to 'O' for next move
            else
                player = 'X';           // switch from 'O' to 'X' for next move
        }
        gameWinner = checkForWinningGame(board); // returns 'X' or 'O' if the game is won
    }
    
    // The game is over. Either the game has been won or no more squares
    displayTicTacToe(board);
    cout << endl;   // blank line
    if (gameWinner =='X' || gameWinner == 'O')
        cout << "Player " << gameWinner << " wins the game" << endl << endl;
    else
        cout << "Tie Game" << endl << endl;

    return 0;
}

// ------ Display the Tic Tac Toe board
void displayTicTacToe(char board[3][3])
{
    cout << endl;
    for (int row=0; row<3; row++)         // display three rows
    {
        for (int col=0; col<3; col++)     // display three columns each row
            cout << board[row][col] << ' ';
        cout << endl;                     // end of row
    }
}

// ------ Check all eight possible combinations for a win.
//  returns the player ('X' or 'O') if the game has been won
//  returns '-' if there is currently no winner
char checkForWinningGame(char board[3][3])
{
    char player;
    
    // check going across the top row to see if all squares are the same
    player = board[0][0];
    if (board[0][1] == player && board[0][2] == player) return player;
    
    // check going across the middle row to see if all squares are the same
    player = board[1][0];
    if (board[1][1] == player && board[1][2] == player) return player;
    // check going across the bottom row to see if all squares are the same
    player = board[2][0];
    if (board[2][1] == player && board[2][2] == player) return player;
    // check going down the first column to see if all squares are the same
    player = board[0][0];
    if (board[1][0] == player && board[2][0] == player) return player;
    // check going down the second column to see if all squares are the same
    player = board[0][1];
    if (board[1][1] == player && board[2][1] == player) return player;
    // check going down the third column to see if all squares are the same
    player = board[0][2];
    if (board[1][2] == player && board[2][2] == player) return player;
    // check going across the left diagonal \ to see if all squares are the same
    player = board[0][0];
    if (board[1][1] == player && board[2][2] == player) return player;
    // check going across the right diagonal / to see if all squares are the same
    player = board[2][0];
    if (board[1][1] == player && board[0][2] == player) return player;
    else
    return '-';     // if there is no winner
}