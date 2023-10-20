#include <iostream>
using namespace std;

int getCount(string str, int size, int answer)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (str[i] == 'A' || str[i] == 'C' || str[i] == 'G' || str[i] == 'T')
        {
            count++;
        }
        else
        {
            break;
        }
    }
    // cout << str << endl;
    return max(answer, count);
}

int main()
{
    // 文字列の入力
    string s;
    cin >> s;
    int answer = 0;

    for (int i = 0; i < s.length(); i++)
    {
        string strSubstr1 = s.substr(0, i);
        answer = getCount(strSubstr1, strSubstr1.length(), answer);

        string strSubstr2 = s.substr(i, s.length() - i);
        answer = getCount(strSubstr2, strSubstr2.length(), answer);
    }

    // 出力
    cout << answer << endl;
    return 0;
}
