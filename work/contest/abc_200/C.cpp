#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 配列内の要素の組み合わせをチェックする代わりに、余りの頻度を記録し、その頻度を使用して条件を満たすペアの数を計算します。
// これにより、計算量が大幅に削減され、プログラムが高速化されます。

int main()
{
    int N;
    cin >> N;
    vector<int> array(N);
    unordered_map<int, int> remainderFreq;

    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
        array[i] %= 200;
        remainderFreq[array[i]]++;
    }
    // N: 6
    // array: 123 223 123 523 200 2000
    // remainderFreq:
    // 余り:一致する個数
    // 0: 2
    // 23: 1
    // 123: 3

    // ある2つの要素Ai​とAj​を200で割った余りが一致するならば、この2要素間で生じうる差は200で割った商の部分だけです。
    // そして、その差は必ず200の倍数となります。

    long long ans = 0;
    for (auto &p : remainderFreq)
    {
        // 単に2個を選び取るだけなので、2つの物体の並び順(2通り存在します)は区別されません。
        // なので、求める場合の数はX×(X−1)/2​となります。
        ans += (long long)p.second * (p.second - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     int N;
//     cin >> N;
//     vector<int> array(N);
//     for (int i = 0; i < N; i++)
//     {
//         cin >> array[i];
//     }

//     int ans = 0;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = i + 1; j < N; j++)
//         {
//             if ((array[i] - array[j]) % 200 == 0)
//             {
//                 ans++;
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }