#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    string ans = "No";

    for (int i = 0; i < N - 1; i++)
    {
        string str = S.substr(i, 2);

        if (str == "ab" || str == "ba")
        {
            ans = "Yes";
        }
    }

    cout << ans << endl;
    return 0;
}