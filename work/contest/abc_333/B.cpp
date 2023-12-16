#include <iostream>
#include <string>
using namespace std;
int main()
{
    string S, T;
    cin >> S, T;
    // 辺の組み合わせ
    string edges = "AB BA BC CB CD DC DE ED EA AE";
    // 対角線の組み合わせ
    string diagonals = "AC CA BD DB CE EC DA AD EB BE";
    if ((edges.find(S) != string::npos && edges.find(T) != string::npos) ||
        (diagonals.find(S) != string::npos && diagonals.find(T) != string::npos))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}