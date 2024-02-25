// TODO

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int ans = 0;
    stack<int> s;
    s.push(N);

    while (!s.empty())
    {
        int num = s.top();
        s.pop();

        if (num >= 2)
        {
            ans += num;
            if (num / 2 >= 2)
            {
                s.push(num / 2);
            }
            if ((num + 1) / 2 >= 2)
            {
                s.push((num + 1) / 2);
            }
        }
    }
    cout << ans << endl;
    return 0;
}