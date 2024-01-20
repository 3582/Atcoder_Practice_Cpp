#include <iostream>
using namespace std;
int main()
{

    int N;
    cin >> N;
    int X = 0, Y = 0;

    for (int i = 0; i < N; i++)
    {
        int t, a;
        cin >> t >> a;
        X += t;
        Y += a;
    }
    if (X > Y)
    {
        cout << "Takahashi" << endl;
    }
    else if (X < Y)
    {
        cout << "Aoki" << endl;
    }
    else
    {
        cout << "Draw" << endl;
    }

    return 0;
}