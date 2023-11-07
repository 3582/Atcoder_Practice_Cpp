#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int64_t count(const vector<int> &A_vec, const vector<int> &C_vec, int B)
{
    auto lb_A = lower_bound(A_vec.begin(), A_vec.end(), B);
    auto ub_C = upper_bound(C_vec.begin(), C_vec.end(), B);

    // lower_boundのイテレータから先頭のイテレータを引くと、あるkeyより小さい要素の個数を求めることができる。
    int64_t cnt_A = lb_A - A_vec.begin();
    // 末尾のイテレータからupper_boundのイテレータを引くと、あるkeyより大きい要素の個数を求めることができる。
    int64_t cnt_C = C_vec.end() - ub_C;
    return cnt_A * cnt_C;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A_vec(N), B_vec(N), C_vec(N);
    for (int i = 0; i < N; ++i)
        cin >> A_vec.at(i);
    for (int i = 0; i < N; ++i)
        cin >> B_vec.at(i);
    for (int i = 0; i < N; ++i)
        cin >> C_vec.at(i);
    sort(A_vec.begin(), A_vec.end());
    sort(C_vec.begin(), C_vec.end());
    int64_t cnt = 0;
    // B_vec.at(i):中部を固定して考える
    for (int i = 0; i < N; ++i)
        cnt += count(A_vec, C_vec, B_vec.at(i));
    cout << cnt << endl;
}
