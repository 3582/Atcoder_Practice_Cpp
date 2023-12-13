#include <iostream>
using namespace std;

int H, W, N;
int A[100000], B[100000], C[100000], D[100000];
int X[1500][1500], Z[1500][1500];

int main()
{
    cin >> H >> W >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    // 長方形領域の四隅に+1,1
    for (int i = 1; i <= N; i++)
    {
        X[A[i]][B[i]] += 1;
        X[A[i]][D[i] + 1] -= 1;
        X[C[i] + 1][B[i]] -= 1;
        X[C[i] + 1][D[i] + 1] += 1;
    }
    // 二次元累積和
    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            Z[i][j] = 0;
        }
    }
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            Z[i][j] = Z[i][j - 1] + X[i][j];
        }
    }
    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= H; j++)
        {
            Z[i][j] = Z[i - 1] + Z[i][j];
        }
    }

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (j >= 2)
            {
                cout << " ";
            }
            cout << Z[i][j];
        }
        cout << endl;
    }

    return 0;
}