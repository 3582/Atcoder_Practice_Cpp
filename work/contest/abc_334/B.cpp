#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ll A, M, L, R;
    cin >> A >> M >> L >> R;
    // LRの範囲内の左端の木と右端の木を求める
    // 端の木の位置 = 端の位置 +- 基準の木までの距離を木の間隔で割った余り
    // 剰余の結果が負の値になるため:(x%M+ M) % M
    ll first = L + ((A - L) % M + M) % M;
    ll last = R - ((R - A) % M + M) % M;

    // 両端の距離を間隔で割り1を足す
    cout << (last - first) / M + 1 << endl;
}
