# Atcoder_Practice_Cpp

```bash
g++ -o out test.cpp
./out 
```

https://ttsuki.github.io/styleguide/cppguide.ja.html

```example
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
```

```input
// N M
// AN,1 AN,2 AN,3... AN,M

long long N, M, A[109][109];

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            cin >> A[i][j];
    }
```

```input
// N
// AN BN

long long N, A[100], B[100], minx = (1LL << 60);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i];
```

```vector
    // g++ -o D-Faction D-Faction.cpp -std=c++17
    vector<vector<int>> graph(12, vector<int>(12));
```

```vector
    int N;
    cin >> N;
    vector<long long> h(N), s(N);
    for (int i = 0; i < N; i++)
        cin >> h[i] >> s[i];
```
