#include <iostream>
using namespace std;

int H, W, Q;
int X[1500][1500], Z[1500][1500];
int A[100000], B[100000], C[100000], D[100000];

int main()
{

    cin >> H >> W;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> X[i][j];
        }
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            Z[i][j] = 0;
        }
    }

    // 累積和
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
            Z[i][j] = Z[i - 1][j] + Z[i][j];
        }
    }

    for (int i = 1; i <= Q; i++)
    {
        cout << Z[A[i] - 1][B[i] - 1] + Z[C[i]][D[i]] - Z[C[i]][B[i] - 1] - Z[A[i] - 1][D[i]] << endl;
    }

    return 0;
}