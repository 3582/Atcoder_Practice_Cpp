// TODO
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    // 穴の個数とボールの個数を表す整数 H, B
    int H, B;
    cin >> H >> B;
    // H 行のうちの i 行目 (1 ≦ i ≦ H) には、i 番目の穴の座標を表す 2 つの整数 x_i, y_i
    vector<vector<int>> H_vec(H, vector<int>(2, 0));
    // B 行のうちの i 行目 (1 ≦ i ≦ B) には、i 番目のボールの初期座標を表す 2 つの整数 p_i, q_i
    vector<vector<int>> B_vec(B, vector<int>(2, 0));
    // グリッドを傾けた履歴を表す文字列 S が与えられます。S は 'R', 'L', 'U', 'D' のみからなり、
    // S の i 文字目が 'R' のとき、ゲーム開始後 i 秒時点から 1 秒間、グリッドが右に傾けられたことを表します
    string S;
    for (int i = 0; i < H; i++)
    {
        cin >> H_vec[i][0] >> H_vec[i][1];
    }
    for (int i = 0; i < B; i++)
    {
        cin >> B_vec[i][0] >> B_vec[i][1];
    }
    cin >> S;

    // 'R', 'L', 'U', 'D'
    // (x+1, y),(x-1, y),(x, y+1),(x, y-1)
    int count = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == 'R')
        {
            for (int j = 0; j < B; j++)
            {
                B_vec[j][0]++;
            }
        }
        if (S[i] == 'L')
        {
            for (int j = 0; j < B; j++)
            {
                B_vec[j][0]--;
            }
        }
        if (S[i] == 'U')
        {
            for (int j = 0; j < B; j++)
            {
                B_vec[j][1]++;
            }
        }
        if (S[i] == 'D')
        {
            for (int j = 0; j < B; j++)
            {
                B_vec[j][1]--;
            }
        }
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < B; j++)
            {
                if (H_vec[i][0] == B_vec[j][0] && H_vec[i][1] == B_vec[j][1])
                {
                    B_vec.erase(B_vec.begin() + j);
                    count++;
                    j--;
                    B--;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}