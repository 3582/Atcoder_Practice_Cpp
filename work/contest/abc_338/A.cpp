#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string S;
    cin >> S;
    if (isupper(S[0]) && all_of(S.begin() + 1, S.end(), ::islower))
    {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}