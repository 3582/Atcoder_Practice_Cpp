#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    // アルファベット26文字
    vector<int> mx(26);
    int l = 0;
    // 文字数
    while (l < n)
    {
        // 次の文字の位置（異なる文字が見つかるまでの位置）
        int r = l + 1;
        // 各アルファベット文字の最大連続長
        while (r < n and s[l] == s[r])
            ++r;
        // 現在の文字を0から25の範囲のインデックスに変換
        // アルファベットの小文字に対して、それぞれの文字を0から25の範囲のインデックスに変換
        // C++では、文字はそのASCII値（アメリカ標準コード情報交換）によって表されます。
        // ASCIIでは、各文字に一意の数字が割り当てられています。例えば、'a' のASCII値は 97、'b' は 98、というようになっています。
        // 例:
        // 文字列 s が "abc" で、変数l が 0 の場合（つまり、s[l] は 'a')
        // s[l] は 'a' です。'a' のASCII値は 97 です。
        // s[l] - 'a' は 97 - 97 で、結果は 0 です。
        // mx[c]はアルファベットの種類のインデックスを指している:例えば、'a' は 0、'b' は 1、... 'z' は 25
        int c = s[l] - 'a';
        // その文字の最大連続長を更新
        mx[c] = max(mx[c], r - l);
        l = r;
    }
    // 合計
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        ans += mx[i];
    }
    cout << ans << endl;
}
