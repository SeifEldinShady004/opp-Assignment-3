#ifndef _TICTACTOE25_HPP
#define _TICTACTOE25_HPP
#include <bits/stdc++.h>
using namespace std;

class Board25
{
    int n_rows = 5, n_cols = 5, n_moves = 24;
    vector<string> board;

public:
    Board25();                                             // Initializes the board as empty
    int wins(char symbol);                                 // Counts the number of collections of size 3 of the specified symbol
                                                           // In other words, counts the character's wins
    char winner(char c1, char c2);                         // Wrapper function for the previous function (int wins(char symbol))
                                                           // Purpose is to choose the winner
    bool update_board(pair<int, int> new_move, char mark); // Returns true if the move is valid, otherwise false
    void display_board();
};

class Player
{
protected:
    string name;
    char symbol;
    pair<int, int> current_move;

public:
    Player();
    Player(char symb);
    virtual void set_move();                           // Sets the player's next move
    virtual void set_name();                           // Setter for player's name
    pair<int, int> get_move() { return current_move; } // Getter for the player's next move
    // Getters for the rest of the player's information
    char get_symbol();
    string get_name();
};

class RandomPlayer : public Player
{
public:
    virtual void set_name(); // Sets the name to "Random Player"
    virtual void set_move(); // Produces a random move
};

class GameManager
{
    Board25 this_round;
    Player player1, player2;

public:
    GameManager();                                    // Initializes an empty board
    GameManager(Board25 board, Player p1, Player p2); // Initializes a normal game (5x5 TicTacToe)
    void run();                                       // Runs the game and starts the experience
};
#endif