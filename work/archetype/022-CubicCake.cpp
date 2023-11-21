#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    // ケーキの幅 A cm, 奥行き B cm, 高さ C cm
    long long A, B, C;
    cin >> A >> B >> C;

    // 立方体ピースの一辺の長さ = A, B, C の最大公約数
    const long long d = gcd(gcd(A, B), C);

    // 合計切断回数 = 幅に関する切断回数 + 奥行きに関する切断回数 + 高さに関する切断回数
    const long long a = (A / d - 1) + (B / d - 1) + (C / d - 1);

    // 解答を出力
    cout << a << endl;
}