#include <iostream>
#include <map>
using namespace std;

int main()
{
    string S;
    cin >> S;
    map<char, int> count;
    for (char c : S)
    {
        count[c]++;
    }
    
    char maxChar = 'a';
    int maxCount = 0;
    for (auto it : count)
    {
        if (it.second > maxCount || (it.second == maxCount && it.first < maxChar))
        {
            maxChar = it.first;
            maxCount = it.second;
        }
    }
    cout << maxChar << endl;

    return 0;
}