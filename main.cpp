#include <iostream>
#include <cstdlib>

char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
const char PLAYER_SYMBOL = 'X';
const char BOT_SYMBOL = 'O';

void drawBoard() {
    system("cls");
    std::cout << "Lets play Tic-Tac-Toe!" << std::endl;
    std::cout << "Select options 1-9 or q to quit." << std::endl;
    std::cout << "Player (X) - Computer (O)" << std::endl;
    std::cout << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " <<  board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " <<  board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " <<  board[6] << " | " << board[7] << " | " << board[8] << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << std::endl;
    std::cout <<  "Select your move: ";
}

void setBoardInput(int position, char symbol) {
    board[position-1] = symbol;
}

void handlePlayerInput() {
    char input;
    std::cin >> input;

    setBoardInput(input - '0', 'X');
}

void handleBotInput() {
    for (int i = 0; i < 9; ++i) {
        int position = (rand() % 9) + 1;
        char boardPositonValue = board[position-1];
        if (boardPositonValue != PLAYER_SYMBOL && boardPositonValue != BOT_SYMBOL) {
            setBoardInput(position, 'O');
            break;
        }
    }
}

int main(int, char**) {
    while(true) {
        drawBoard();
        handlePlayerInput();
        handleBotInput();
    }
}
