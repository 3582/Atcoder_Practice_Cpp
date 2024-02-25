#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i)
    {
        cin >> grid[i];
    }

    int count = 0;
    for (int i = 1; i < H - 1; ++i)
    {
        for (int j = 1; j < W - 1; ++j)
        {
            if (grid[i][j] == '.' &&
                grid[i - 1][j] == '#' &&
                grid[i + 1][j] == '#' &&
                grid[i][j - 1] == '#' &&
                grid[i][j + 1] == '#' &&
                grid[i - 1][j - 1] == '#' &&
                grid[i - 1][j + 1] == '#' &&
                grid[i + 1][j - 1] == '#' &&
                grid[i + 1][j + 1] == '#')
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
