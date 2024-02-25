#include<iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> charCount;
    
    for (char c : s) {
        charCount[c]++;
    }
    int count = 1;
    for (char c : s) {
        if (charCount[c] == 1) {
            break;
        }
        count ++;
    }
    cout << count << endl;
    return 0;
}
