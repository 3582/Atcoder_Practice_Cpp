#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> result(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> A.at(i);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; j++)
        {
            if (A.at(i) < A.at(j))
            {
                result.at(i) += A.at(j);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << result.at(i);
        if (i + 1 != N)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }

    return 0;
}
