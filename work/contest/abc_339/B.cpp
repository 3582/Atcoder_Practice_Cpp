#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<char>> grid(H, vector<char>(W, '.')); 
    int h = 0;
    int w = 0;
    int direction = 0;

    vector<int> dh = {-1, 0, 1, 0};
    vector<int> dw = {0, 1, 0, -1};

    for (int i = 0; i < N; i++)
    {
        if (grid[h][w] == '.')
        {
            grid[h][w] = '#';
            direction = (direction + 1) % 4; 
        }
        else
        {
            grid[h][w] = '.';
            direction = (direction + 3) % 4; 
        }
        h = (h + dh[direction] + H) % H; 
        w = (w + dw[direction] + W) % W; 
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}