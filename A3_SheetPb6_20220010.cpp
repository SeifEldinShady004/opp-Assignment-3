#include <bits/stdc++.h>
using namespace std;

class Universe
{
    int rows, cols;
    vector<vector<bool>> grid;

public:
    Universe(int r, int c)
    {
        rows = r;
        cols = c;
        grid = vector<vector<bool>>(r, vector<bool>(c, false));
    }

    ~Universe() = default;

    void initialize()
    {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                grid[i][j] = rand() % 2 == 1;
        display();
        cout << "The above is the initial state.\n\n";
    }

    void reset()
    {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                grid[i][j] = false;
    }

    int count_neighbors(int row, int col)
    {
        int neighbors = 0;
        if (row - 1 >= 0)
            neighbors += grid[row - 1][col];
        if (row + 1 < rows)
            neighbors += grid[row + 1][col];
        if (col - 1 >= 0)
            neighbors += grid[row][col - 1];
        if (col + 1 < cols)
            neighbors += grid[row][col + 1];
        return neighbors;
    }

    void next_generation()
    {
        vector<vector<bool>> newGrid(rows, vector<bool>(cols, false));

        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                int alive_neighbors = count_neighbors(row, col);
                bool alive = grid[row][col];
                newGrid[row][col] = (alive_neighbors == 3) || (alive && alive_neighbors == 2);
            }
        }

        grid = newGrid;
    }

    void display() const
    {
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
                cout << (grid[row][col] ? " ## " : " .. ");
            cout << '\n';
        }
        cout << "\n\n";
    }

    void run(int generations)
    {
        while (generations--)
        {
            next_generation();
            display();
        }
    }
};

int main()
{
    Universe gameOfLife(5, 5);
    gameOfLife.initialize();
    gameOfLife.run(2);

    Universe round_two(7, 7);
    round_two.initialize();
    round_two.run(3);

    Universe one_more(9, 9);
    one_more.initialize();
    one_more.run(3);
}
