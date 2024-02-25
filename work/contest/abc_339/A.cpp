#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string S;
    string ans = "";
    cin >> S;
    reverse(S.begin(), S.end());
    int it = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '.')
        {
            it = i;
            break;
        }
    }

    for (int i = it - 1; i >= 0; i--)
    {
        cout << S[i];
    }
    cout << endl;

    return 0;
}