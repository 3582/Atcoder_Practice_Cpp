#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> grid(2000, vector<int>(2000));

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
            cin >> grid[i][j];
    }

    vector<int> yoko(H, 0); // i 行目の総和
    vector<int> tate(W, 0); // j 列目の総和
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            yoko[i] += grid[i][j];
            tate[j] += grid[i][j];
        }
    }

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cout << yoko[i] + tate[j] - grid[i][j];
            if (j != W - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
