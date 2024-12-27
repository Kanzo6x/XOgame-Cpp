#include <iostream>
using namespace std;

void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool checkWin(char board[3][3]) { 
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true; 
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true; 
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true; 
    return false;
}

void XOGame() {
    while (true) {
        char board[3][3] = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
        };
        char players[2] = {'X', 'O'};
        int counter = 0;
        int moves = 0;
        bool gameWon = false;

        displayBoard(board);

        while (moves < 9) {
            int cell;
            char currentPlayer = players[counter % 2];
            cout << "Player " << currentPlayer << ", enter a number (1-9): ";

            cin >> cell;
            while (cell < 1 || cell > 9) {
                cout << "Invalid input. Enter a number between 1 and 9: ";
                cin >> cell;
            }

            int row = 0;
            int col = 0;
            if (cell == 1) { row = 0; col = 0; }
            else if (cell == 2) { row = 0; col = 1; }
            else if (cell == 3) { row = 0; col = 2; }
            else if (cell == 4) { row = 1; col = 0; }
            else if (cell == 5) { row = 1; col = 1; }
            else if (cell == 6) { row = 1; col = 2; }
            else if (cell == 7) { row = 2; col = 0; }
            else if (cell == 8) { row = 2; col = 1; }
            else if (cell == 9) { row = 2; col = 2; }

            if (board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "Cell already taken. Choose another cell.\n";
                continue;
            }

            board[row][col] = currentPlayer;
            moves++;
            displayBoard(board);

            if (checkWin(board)) {
                cout << "Player " << currentPlayer << " wins!\n";
                gameWon = true;
                break;
            }

            counter++;
        }

        if (!gameWon) {
            cout << "It's a tie!\n";
        }

        char playAgain;
        cout << "Do you want to play another game? (y/n): ";
        cin >> playAgain;
        if (tolower(playAgain) != 'y') {
            break;
        }
    }
}

int main() {
    XOGame();
    return 0;
}


