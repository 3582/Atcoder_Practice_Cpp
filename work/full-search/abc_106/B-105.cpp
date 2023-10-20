/*
105 という数は, 非常に特殊な性質を持つ - 奇数なのに, 約数が8 個もある
さて,1 以上N 以下の奇数のうち, 正の約数を ちょうど8 個持つようなものの個数を求めよ
N は1 以上200 以下の整数
入力は以下の形式で標準入力から与えられる
N
*/
#include <iostream>
using namespace std;
int main()
{
    // 整数の入力
    int N;
    cin >> N;
    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        int count = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
        }
        if (count == 8)
        {
            answer++;
        }
    }

    // 出力
    cout << answer << endl;
    return 0;
}
