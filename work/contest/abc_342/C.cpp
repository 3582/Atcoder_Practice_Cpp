#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int H, W, N;
    cin >> H >> W >> N;
    vector<string> T;
    int result = 0;
    string temp;
    cin >> temp;
    for (int i = 0; i < N; i++)
    {
        T.push_back(string(1, temp[i]));
    }
    vector<vector<string>> S(H);

    for (int i = 0; i < H; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < W; j++)
        {
            S[i].push_back(string(1, temp[j]));
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (S[i][j] == "#")
            {
                continue;
            }
            int tmp_h, tmp_w;
            tmp_h = i;
            tmp_w = j;
            bool ok = true;
            for (int k = 0; k < N; k++)
            {
                if (T[k] == "L")
                    tmp_w--;
                if (T[k] == "R")
                    tmp_w++;
                if (T[k] == "U")
                    tmp_h--;
                if (T[k] == "D")
                    tmp_h++;
                if (S[tmp_h][tmp_w] == "#")
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                result++;
        }
    }
    cout << result << endl;
    return 0;
}
