// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B&lang=ja
// 1 から n までの数の中から、重複無しで３つの数を選びそれらの合計が x となる組み合わせの数を求めるプログラムを作成して下さい。
/* Sample Input
5 9
0 0
*/
/*
Sample Output
2
*/
#include <iostream>
using namespace std;
int main()
{
    while (true)
    {
        int n, x;
        cin >> n >> x;

        if (n == 0 && x == 0)
        {
            return 0;
        }
        int answer = 0;

        for (int a = 1; a <= n; a++)
        {
            for (int b = 1 + a; b <= n; b++)
            {
                for (int c = 1 + b; c <= n; c++)
                {
                    if (a + b + c == x)
                    {
                        // cout << a << " " << b << " " << c << endl;
                        answer++;
                    }
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
}
