#include <iostream>
using namespace std;
int main()
{
    int ans = 0;
    int K, G, M;
    cin >> K >> G >> M;
    int glass, mug = 0;
    for (int i = 1; i <= K; i++)
    {
        if (glass == G)
        {
            glass = 0;
        }
        else if (mug == 0)
        {
            mug = M;
        }
        else
        {
            while (mug > 0)
            {
                if (glass == G)
                    break;
                mug -= 1;
                glass += 1;
            }
        }
    }

    cout << glass << " " << mug << endl;
    return 0;
}