#include "tictactoe25.hpp"
#include "tictactoe25.cpp"
int main()
{
    Board25 tictactoe;
    Player p1('X'), p2('O');

    GameManager xogame(tictactoe, p1, p2);
    xogame.run();
}
