# Atcoder_Practice_Cpp

```bash
g++ -o out test.cpp
./out 
```

https://ttsuki.github.io/styleguide/cppguide.ja.html

#include<iostream>
using namespace std;
int main()
{
    int ans = 0;
    // 整数の入力
    int a;
    cin >> a;
    // スペース区切りの整数の入力
    int b,c;
    cin >> b >> c;
    // 文字列の入力
    string s;
    cin >> s;
    // 出力
    cout << ans << endl;
    return 0;
}

```input
N M
AN,1 AN,2 AN,3... AN,M
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            cin >> A[i][j];
    }
```
