#include <iostream>

using namespace std;

string toBinary(unsigned int n)
{
    string binary = "";
    while (n > 0)
    {
        binary = to_string(n % 2) + binary;
        n = n / 2;
    }
    return binary;
}

int main()
{
    int N;
    cin >> N;
    int count = 0;
    string str = toBinary(N);
    for (int i = str.length() - 1; i >= 0; --i)
    {
        if (str[i] == '0')
        {
            ++count;
        }
        else
        {
            break;
        }
    }
    cout << count << endl;

    return 0;
}