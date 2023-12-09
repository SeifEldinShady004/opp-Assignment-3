#include "tictactoe25.hpp"
// Board25 class implementation starts here --------------------------
Board25::Board25()
{
    for (int i = 0; i < 5; i++)
        board.push_back(".....");
}
int Board25::wins(char symbol)
{
    int num_of_wins = 0;
    // horizontal wins first
    for (int i = 0; i < n_rows; i++)
    {
        bool a = board[i].substr(0, 3) == string(3, symbol);
        bool b = board[i].substr(1, 3) == string(3, symbol);
        bool c = board[i].substr(2, 3) == string(3, symbol);
        num_of_wins += (a + b + c);
    }

    // vertical wins second
    for (int j = 0; j < 5; ++j)
    {
        string new_str = "";
        for (int i = 0; i < 5; i++)
            new_str += board[i][j];
        bool a = new_str.substr(0, 3) == string(3, symbol);
        bool b = new_str.substr(1, 3) == string(3, symbol);
        bool c = new_str.substr(2, 3) == string(3, symbol);
        num_of_wins += (a + b + c);
    }
    //  diagonal wins last (left to right)
    for (int i : {0, 1, 2})
    {
        string new_str = "";
        for (int j : {0, 1, 2})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";

        for (int j : {1, 2, 3})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";

        for (int j : {2, 3, 4})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";
    }
    for (int i : {1, 2, 3})
    {
        string new_str = "";
        for (int j : {0, 1, 2})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";

        for (int j : {1, 2, 3})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";

        for (int j : {2, 3, 4})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";
    }
    for (int i : {2, 3, 4})
    {
        string new_str = "";
        for (int j : {0, 1, 2})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";

        for (int j : {1, 2, 3})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";

        for (int j : {2, 3, 4})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";
    }
    //  diagonal wins last (right to left)
    for (int i : {4, 3, 2})
    {
        string new_str = "";
        for (int j : {4, 3, 2})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";

        for (int j : {3, 2, 1})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";

        for (int j : {2, 1, 0})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";
    }
    for (int i : {3, 2, 1})
    {
        string new_str = "";
        for (int j : {4, 3, 2})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";

        for (int j : {3, 2, 1})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";

        for (int j : {2, 1, 0})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";
    }
    for (int i : {2, 1, 0})
    {
        string new_str = "";
        for (int j : {4, 3, 2})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";

        for (int j : {3, 2, 1})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";

        for (int j : {2, 1, 0})
            new_str += board[i][j];
        num_of_wins += (new_str == string(3, symbol));
        new_str = "";
    }
    return num_of_wins;
}
char Board25::winner(char c1, char c2)
{
    if (wins(c1) > wins(c2))
        return c1;
    else if (wins(c2) > wins(c1))
        return c2;
    else
        return 'D';
}
bool Board25::update_board(pair<int, int> new_move, char mark)
{
    if (new_move.first > 5 || new_move.second > 5)
        return false;
    else if (board[new_move.first][new_move.second] != '.')
    {
        cout << "Move already made.\n";
        return false;
    }
    else
    {
        board[new_move.first][new_move.second] = mark;
        return true;
    }
}
void Board25::display_board()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}
// Board25 class implementation ends here --------------------------

// Player class implementation starts here --------------------------
Player::Player() : name("Auto"), symbol('#') { cout << "This player has the name: Auto. His symbol is '#'.\n"; }
Player::Player(char symb) : symbol(symb) {}
void Player::set_move()
{
    cout << "please enter your move (row col): ";
    cin >> current_move.first >> current_move.second;
}
void Player::set_name() { cin >> name; }
char Player::get_symbol() { return symbol; }
string Player::get_name() { return name; }
// Player class implementation ends here --------------------------

// RandomPlayer class implementation starts here --------------------------
void RandomPlayer::set_name() { name = "Random Player"; }
void RandomPlayer::set_move()
{
    srand(time(0));
    current_move.first = rand() % 5;
    current_move.second = rand() % 5;
}
// RandomPlayer class implementation ends here --------------------------

// GameManager class implementation starts here --------------------------
GameManager::GameManager() : this_round(Board25()), player1(Player('X')), player2(Player('O')) {}
GameManager::GameManager(Board25 board, Player p1, Player p2) : this_round(board), player1(p1), player2(p2) {}
void GameManager::run()
{
    cout << "Welcome to the 5x5 TicTacToe Game. :)\n\n";
    cout << "1st Player, please enter your name: \n";
    player1.set_name();
    cout << "2nd Player, please enter your name: \n";
    player2.set_name();
    int moves_made = 0;
    char c1 = player1.get_symbol(), c2 = player2.get_symbol();
    bool p1_turn = true;

    while (moves_made < 24)
    {
        if (p1_turn)
        {
            bool valid_move = false;
            while (!valid_move)
            {
                cout << player1.get_name() << ", ";
                player1.set_move();
                pair<int, int> new_move = player1.get_move();
                valid_move = this_round.update_board(new_move, c1);
                if (!valid_move)
                    cout << "Invalid move. Please try again.\n";
            }
            cout << "\nMoves made = " << ++moves_made << '\n';
            p1_turn ^= 1;
            this_round.display_board();
        }
        else
        {
            bool valid_move = false;
            while (!valid_move)
            {
                player2.set_move();
                pair<int, int> new_move = player2.get_move();
                valid_move = this_round.update_board(new_move, c2);
                if (!valid_move)
                    cout << "Invalid move. Please try again.\n";
            }
            cout << "\nMoves made = " << ++moves_made << '\n';
            p1_turn ^= 1;
            this_round.display_board();
        }
    }

    if (this_round.winner(c1, c2) == c1)
        cout << "Congratulations, " + player1.get_name() + ". You are the winner.\n\n";
    else if (this_round.winner(c1, c2) == c2)
        cout << "Congratulations, " + player2.get_name() + ". You are the winner.\n\n";
    else
        cout << "This is a draw.\n\n";
}
// GameManager class implementation ends here --------------------------