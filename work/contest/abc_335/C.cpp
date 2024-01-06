#include <iostream>
using namespace std;

int N, Q;
int query[200009];
int dragon[200009][2];
string C[200009];

int main()
{
    cin >> N >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> query[i] >> C[i];
    }
    for (int i = 1; i <= N; i++)
    {
        dragon[i][0] = i;
        dragon[i][1] = 0;
    }

    for (int i = 0; i < Q; i++)
    {
        if (query[i] == 1)
        {
            for (int j = N; j >= 2; j--)
            {
                dragon[j][0] = dragon[j - 1][0];
                dragon[j][1] = dragon[j - 1][1];
            }

            if (C[i] == "R")
            {
                dragon[1][0] = dragon[1][0] + 1;
            }
            if (C[i] == "L")
            {
                dragon[1][0] = dragon[1][0] - 1;
            }
            if (C[i] == "U")
            {
                dragon[1][1] = dragon[1][1] + 1;
            }
            if (C[i] == "D")
            {
                dragon[1][1] = dragon[1][1] - 1;
            }
        }
        if (query[i] == 2)
        {
            int index = stoi(C[i]);
            cout << dragon[index][0] << " " << dragon[index][1] << endl;
        }
    }

    return 0;
}