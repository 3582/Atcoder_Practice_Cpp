#include <iostream>
using namespace std;
int main()
{
    int H, W, X[1500][1500], Q, A[100000], B[100000], C[100000], D[100000];
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> X[i][j];
        }
    }

    return 0;
}