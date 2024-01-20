#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string S;
    cin >> S;
    bool allA = true;
    bool allB = true;
    bool allC = true;

    if (S.empty())
    {
        cout << "Yes" << endl;
        return 0;
    }

    for (char c : S)
    {
        if (c != 'A')
        {
            allA = false;
            break;
        }
    }
    for (char c : S)
    {
        if (c != 'B')
        {
            allB = false;
            break;
        }
    }
    for (char c : S)
    {
        if (c != 'C')
        {
            allC = false;
            break;
        }
    }

    vector<int> Sa, Sb, Sc;
    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[i] == 'A')
        {
            Sa.push_back(i);
        }
        else if (S[i] == 'B')
        {
            Sb.push_back(i);
        }
        else if (S[i] == 'C')
        {
            Sc.push_back(i);
        }
    }

    vector<int> concatenatedS;
    concatenatedS.insert(concatenatedS.end(), Sa.begin(), Sa.end());
    concatenatedS.insert(concatenatedS.end(), Sb.begin(), Sb.end());
    concatenatedS.insert(concatenatedS.end(), Sc.begin(), Sc.end());
    bool abc = true;
    for (size_t i = 0; i < concatenatedS.size(); i++)
    {
        if (concatenatedS[i] != static_cast<int>(i))
        {
            abc = false;
        }
    }
    if (abc || allA || allB || allC)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
