/*
 *  ===============================================================
 *
 *  Filename:   tesla.cpp
 *
 *  Description: STARMAN game
 *
 *  Version: 3.0
 *  Created: 06/30/2020
 *  Compiler: g++
 *
 *  Team: Code Monkeys
 *  Authors: Doug Emery, Jack Armstrong, Mitch Buckey, & Grant Hineline
 *
 * =================================================================
 *
*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <ctime>

using namespace std;

const int ROOM = 15;                                            // Room Size global

// Function Prototypes
void StartChar(char(&arr)[ROOM][ROOM], int(&pos)[2]);
bool MoveChar(char(&room)[ROOM][ROOM], char input, int(&pos)[2]);
void MoveElon(char(&objects)[ROOM][ROOM], int(&pos)[2]);
void FindEmptySpot(char(&Objects)[ROOM][ROOM], int& x, int& y);
void ObjectsLocation(char(&Objects)[ROOM][ROOM]);
bool CheckBox(char(&arr)[ROOM][ROOM], char(&arr2)[ROOM][ROOM], int(&pos)[2], int(&Elon)[2]);
void ClearBox(char(&arr)[ROOM][ROOM], int(&pos)[2]);
void GiveHint(int(&TPos)[2], int(&User)[2], char input);
bool WrongCar(char(&arr)[ROOM][ROOM], int(&User)[2]);
void RoomDisplay(char(&arr)[ROOM][ROOM]);

int main()
{
    srand(time(NULL));
    char gameDecision = 'z';                                        // New game variable
    int numGames = 0;                                               // Number of games played
    int winCount = 0;                                               // Win counter
    int starmanCount = 0;                                           // Loss counter
    char move = '0';                                                // Move choice
    bool currentmove;                                               // Valid move check
    bool See;                                                       // Checks if safe to see
    int UserPos[2] = { 0,0 };                                         // User position
    int EMPos[2] = { 0,0 };                                           // Elon position
    int TRPos[2] = { 0,0 };                                           // Tesla Roadster position

    //Game info for user
    cout << "\nWelcome to the Find the Tesla Roadster game! " << endl;
    cout << "The goal of this game is to move your character(the X) around the factory to find the roadster ($) and get into it." << endl;
    cout << "There are also two other cars in the factory, the yugo (&) and the pinto (#)." << endl;
    cout << "If you get in them, you will become the 'Starman' and lose the game." << endl;
    cout << "To get in any car, move your character onto the same spot the symbol is on. Once you get in the Roadster, you win!" << endl;
    cout << "But beware! ELon (!) is asleep in the factory. Be careful to not wake him up, or he will start searching for you!" << endl;
    cout << "If he catches you once, you can escape, but the next time you are caught, " << endl;
    cout << "you will become the 'Starman' and be sent up to space." << endl;
    cout << "Good luck and happy hunting!" << endl << endl;

    while (gameDecision != 'n' && move != 'q')                      // Outer loop for repeated games
    {
        size_t movecount = 0;                                       // Number of moves
        bool gameStatus = true;                                     // Checks to see if game ends
        string playerStatus = "NULL";                               // Player status
        size_t WakeElon = (rand() % 5) + 5;                         // Wake Elon value
        int SeeElon = 0;                                            // Elon See count

        char room[ROOM][ROOM];                                      // Initialize room
        memset(room, '*', 15 * 15 * sizeof(room[0][0]));            // Fill room with chars

        char objects[ROOM][ROOM];                                   // Initialize objects
        memset(objects, '*', 15 * 15 * sizeof(objects[0][0]));      // Fill room with default chars

        ObjectsLocation(objects);                                   // Call function to fill room with cars/Elon

        // double for loop that finds Elon and Roadster, saves location
        for (int i = 0; i < ROOM; i++)
        {
            for (int j = 0; j < ROOM; j++)
            {
                if (objects[i][j] == '!')
                {
                    EMPos[0] = i;
                    EMPos[1] = j;
                }
                if (objects[i][j] == '$')
                {
                    TRPos[0] = i;
                    TRPos[1] = j;
                }
            }
        }
        StartChar(objects, UserPos);                                // Starts user position
        room[UserPos[0]][UserPos[1]] = 'X';                         // Edits display array
        RoomDisplay(room);                                          // Displays room

        cout << "\nTo move: enter W for up, A for left, S for down, D for right. To quit, enter Q: ";
        cin >> move;                                                // Move variable assigned
        move = tolower(move);                                       // Forces input to lowercase

        while (move != 'q' && gameStatus == true)                   // Inner loop for winning, losing, or quitting
        {
            currentmove = MoveChar(room, move, UserPos);              // Bool variable assigned to move function
            if (!currentmove)                                       // Checks for valid move
            {
                cout << "Invalid move entered, please choose a valid move (W, A, S, D, Q to quit): ";
                cin >> move;
                move = tolower(move);
                continue;
            }
            ++movecount;                                            // Move counter incremented

            if (movecount >= WakeElon)                              // Checks if enough moves have occurred to initiate
            {                                                       /// Elon to move
                MoveElon(objects, EMPos);                           // Move Elon function
            }

            bool wrongcar = WrongCar(objects, UserPos);             // Checks to see if user has entered incorrect car
            if (wrongcar)
            {
                playerStatus = "Starman";                           // Assigns losing condition
                gameStatus = false;                                 // Assigns ending game condition
                continue;                                           // Passes to conditional check
            }

            See = CheckBox(objects, room, UserPos, EMPos);          // Assigns bool to account for being seen by Elon
            if (See) {
                SeeElon += 1;                                       // Increments Elon seen counter
                cout << "Elon seen " << SeeElon << " times" << endl;// Outputs Elon seen counter
                if (SeeElon >= 2)                                   // Checks if seen counter reaches max
                {
                    playerStatus = "Starman";                       // Assigns losing condition
                    gameStatus = false;                             // Assigns ending game condition
                    continue;                                       // Passes to conditional check
                }
            }
            if ((UserPos[0] == TRPos[0] && UserPos[1] == TRPos[1])) // Checks if user position is at roadster position
            {
                playerStatus = "Win";                               // Assigns winning condition
                gameStatus = false;                                 // Assigns ending game condition
                continue;                                           // Passes to conditional check
            }

            RoomDisplay(room);                                      // Room display function

            GiveHint(TRPos, UserPos, move);                         // Gives a hint function
            ClearBox(room, UserPos);                                // Function call for removing array edits
            cout << "\nTo move: enter W for up, A for left, S for down, D for right. To end, enter Q: ";
            cin >> move;
            move = tolower(move);
        }
        cout << "\nHere's the Result! - \n" << endl;                // Output for results
        RoomDisplay(objects);                                       // Displays the object placement
        cout << "\n\n";
        RoomDisplay(room);                                          // Displays room for player

        if (playerStatus == "Win")                                  // Win Report
        {
            ++numGames;                                             // Increments game count
            ++winCount;                                             // Increments win count
            cout << "\nCongratulations! You won! Here are your game stats: " << endl;
            cout << "Number of moves it took to find the Roadster: " << movecount << endl;
            cout << "Number of games played: " << numGames << endl;
            cout << "Number of times Roadster was found: " << winCount << endl;
            cout << "Number of times you became the 'Starman': " << starmanCount << endl;
            cout << "Play again? Press (y) for yes, (n) for no: ";
            cin >> gameDecision;                                    // Assigns new game variable
            gameDecision = tolower(gameDecision);
            cout << "\n";
        }
        else if (playerStatus == "Starman")                         // Loss Report
        {
            ++numGames;                                             // Increments game count
            ++starmanCount;                                         // Increments win count
            cout << "\nSorry, but you lost. Here are your game stats: " << endl;
            cout << "Number of moves taken: " << movecount << endl;
            cout << "Number of games played: " << numGames << endl;
            cout << "Number of times you became the 'Starman': " << starmanCount << endl;
            cout << "Play again? Press (y) for yes, (n) for no: ";
            cin >> gameDecision;                                    // Assigns new game variable
            gameDecision = tolower(gameDecision);
            cout << "\n";
        }
        else if (playerStatus == "NULL")                            // Quit Report
        {
            cout << "\nThank you for playing!" << endl;
            cout << "Here are the final stats: " << endl;
            cout << "Number of games played: " << numGames << endl;
            cout << "Number of times Roadster was found: " << winCount << endl;
            cout << "Number of times you became the 'Starman': " << starmanCount << endl;
        }
    }
    return 0;
}

// Starting position function for user
void StartChar(char(&arr)[ROOM][ROOM], int(&pos)[2]) {
    int y, x;
    FindEmptySpot(arr, y, x);                                       // Finds empty spot for user
    pos[0] = y;                                                     // Assigns row position
    pos[1] = x;                                                     // Assigns col position
}
// Moving user function with valid move check
bool MoveChar(char(&room)[ROOM][ROOM], char input, int(&pos)[2]) {
    int y, x;
    bool ValidMove = true;                                          // Assigns valid move
    y = pos[0];                                                     // Assigns y variable
    x = pos[1];                                                     // Assigns x variable
    int temp_y = y;                                                 // Assigns temporary y var
    int temp_x = x;                                                 // Assigns temporary x var

    input = tolower(input);

    switch (input)                                                  // Switch case for move input
    {
    case 'w':
        if (y == 0)                                                 // Checks if at edge of room
        {
            ValidMove = false;
        }
        else
        {
            y -= 1;                                                 // Decrements y var
        }
        break;

    case 'a':
        if (x == 0)                                                 // Checks if at edge of room
        {
            ValidMove = false;
        }
        else
        {
            x -= 1;                                                 // Decrements x var
        }
        break;

    case 's':
        if (y == 14)                                                // Checks if at edge of room
        {
            ValidMove = false;
        }
        else
        {
            y += 1;                                                  // Icrements y var
        }
        break;

    case 'd':
        if (x == 14)                                                // Checks if at edge of room
        {
            ValidMove = false;
        }
        else
        {
            x += 1;                                                 // Increments x var
        }
        break;

    case 'q':                                                       // Quit case
        break;

    default:                                                        // Invalid input default case
        ValidMove = false;
        break;
    }
    room[temp_y][temp_x] = '*';                                     // Reassigns past position to default char
    room[y][x] = 'X';                                               // Assigns new location for user
    pos[0] = y;                                                     // Edits user's row position
    pos[1] = x;                                                     // Edits user's col position

    return ValidMove;                                               // Returns validmove bool
}
// Move elon function
void MoveElon(char(&objects)[ROOM][ROOM], int(&pos)[2]) {
    int step;                                                       // Step direction variable
    int y, x;
    y = pos[0];                                                     // Assigns y pos
    x = pos[1];                                                     // Assigns x pos
    int temp_y = y;                                                 // Assigns temp y pos
    int temp_x = x;                                                 // Assigns temp x pos

    while (objects[y][x] != '*')                                    // Checks [y][x] pos in array if not default char
    {
        step = rand() % 4;                                          // Assigns random 0-3 value for step direction

        switch (step)
        {
        case 0:                                                     // Move up
            if (y == 0)                                             // At room edge
            {
                break;
            }
            else if (objects[y - 1][x] == '*')                        // Unfilled space
            {
                y -= 1;                                             // New location
                break;
            }
            break;

        case 1:                                                     // Move down
            if (y == 14)                                            // At room edge
            {
                break;
            }
            else if (objects[y + 1][x] == '*')                        // Unfilled space
            {
                y += 1;                                             // New location
                break;
            }
            break;

        case 2:                                                     // Move left
            if (x == 0)                                             // At room edge
            {
                break;
            }
            else if (objects[y][x - 1] == '*')                        // Unfilled space
            {
                x -= 1;
                break;
            }
            break;

        case 3:                                                     // Move right
            if (x == 14)                                            // At room edge
            {
                break;
            }
            else if (objects[y][x + 1] == '*')                        // Unfilled space
            {
                x += 1;
                break;
            }
            break;
        }
    }

    pos[0] = y;                                                     // Assigns new row position
    pos[1] = x;                                                     // Assigns new col position
    objects[y][x] = '!';                                            // Edit new location
    objects[temp_y][temp_x] = '*';                                  // Reset past location

}
// Find empty spot function, checks for spot unoccupied room spot
void FindEmptySpot(char(&arr)[ROOM][ROOM], int& y, int& x) {
    y = (rand() % ROOM);
    x = (rand() % ROOM);

    while (arr[y][x] != '*') {
        y = (rand() % ROOM);
        x = (rand() % ROOM);
    }
}
// Sets locations of cars and elon in array
void ObjectsLocation(char(&Objects)[ROOM][ROOM]) {
    int x, y;

    x = 0;
    y = 0;

    //Location of the yugo
    FindEmptySpot(Objects, y, x);
    Objects[y][x] = '&';

    //Location of the pinto
    FindEmptySpot(Objects, y, x);
    Objects[y][x] = '#';

    //Location of and the roadster
    FindEmptySpot(Objects, y, x);
    Objects[y][x] = '$';

    //Location of Elon Musk
    FindEmptySpot(Objects, y, x);
    Objects[y][x] = '!';
}
// Bool function for checking 3x3 box and if Elon is found in box
bool CheckBox(char(&arr)[ROOM][ROOM], char(&arr2)[ROOM][ROOM], int(&pos)[2], int(&Elon)[2]) {
    bool ElonSeen = false;
    for (int i = (pos[0] - 1); i <= (pos[0] + 1); i++)
    {
        for (int j = (pos[1] - 1); j <= (pos[1] + 1); j++)
        {
            if (i == pos[0] && j == pos[1])                         // Passes by current position
            {
                continue;
            }
            else if (i < 0 || i > 14 || j < 0 || j > 14)             // Passes by cases beyond room's bounds
            {
                continue;
            }
            else
            {
                arr2[i][j] = arr[i][j];                             // Edits array to show chars in box
            }
            if (Elon[0] == i && Elon[1] == j)                       // Checks if elon is seen
            {
                ElonSeen = true;
            }

        }
    }
    return ElonSeen;
}
// Function to remove edits made by checkbox
void ClearBox(char(&arr)[ROOM][ROOM], int(&pos)[2]) {
    for (int i = (pos[0] - 1); i <= (pos[0] + 1); i++)
    {
        for (int j = (pos[1] - 1); j <= (pos[1] + 1); j++)
        {
            if (i == pos[0] && j == pos[1])
            {
                continue;
            }
            else if (i < 0 || i > 14 || j < 0 || j > 14)
            {
                continue;
            }
            else
            {
                arr[i][j] = '*';
            }
        }
    }
}
// Function to give user hints
void GiveHint(int(&TPos)[2], int(&User)[2], char input) {
    double dist_0, dist_1;
    double TP[2], UP[2];

    for (int i = 0; i < 2; i++)                                     // Sets local array values for tesla & user pos
    {
        TP[i] = TPos[i];
        UP[i] = User[i];
    }

    dist_1 = sqrt(pow(TP[0] - UP[0], 2) + pow(TP[1] - UP[1], 2));   // post move distance

    switch (input)                                                  // Calculates premove distance
    {
    case 'w':
        dist_0 = sqrt(pow(TP[0] - (UP[0] + 1), 2) + pow(TP[1] - UP[1], 2));
        break;

    case 's':
        dist_0 = sqrt(pow(TP[0] - (UP[0] - 1), 2) + pow(TP[1] - UP[1], 2));
        break;

    case 'a':
        dist_0 = sqrt(pow(TP[0] - (UP[0]), 2) + pow(TP[1] - (UP[1] + 1), 2));
        break;

    case 'd':
        dist_0 = sqrt(pow(TP[0] - (UP[0]), 2) + pow(TP[1] - (UP[1] - 1), 2));
        break;

    default:
        break;
    }

    if (dist_1 < dist_0) {                                           // Compares distances if closer or further
        cout << "You are getting warmer!" << endl;
    }
    else if (dist_1 > dist_0)
    {
        if (TP[0] == UP[0] || TP[1] == UP[1]) {
            cout << "I think you should turn around..." << endl;
        }
        else {
            cout << "You are getting colder." << endl;
        }
    }
}
// Bool function for checking if user enters a wrong car
bool WrongCar(char(&arr)[ROOM][ROOM], int(&User)[2]) {
    int y, x;
    y = User[0];
    x = User[1];
    if (arr[y][x] == '&' || arr[y][x] == '#')
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Function to print the room arrays
void RoomDisplay(char(&arr)[ROOM][ROOM]) {
    for (int i = 0; i < ROOM; i++)
    {
        for (int j = 0; j < ROOM; j++)
        {
            cout << arr[i][j];
            if (j == 14)
            {
                cout << "\n";
            }
        }
    }
}