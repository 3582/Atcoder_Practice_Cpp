#include <iostream>
using namespace std;

// N日、Sの予定、無地シャツの枚数M
int N, M;
string S;

bool check(int x)
{
    // 無地M、ロゴ入りx
    int muji = M;
    int logo = x;

    for (int i = 0; i < N; i++)
    {
        if (S[i] == '0')
        {
            muji = M;
            logo = x;
            continue;
        }
        if (S[i] == '1')
        {
            // 無地は用途が限定されているため優先して使用する
            if (muji > 0)
            {
                muji--;
                continue;
            }
            if (logo > 0)
            {
                logo--;
                continue;
            }
            return false;
        }
        if (S[i] == '2')
        {
            if (logo > 0)
            {
                logo--;
                continue;
            }
            return false;
        }
    }
    // N日間シャツが足りている
    return true;
}

int main()
{
    // 6 1
    // 112022
    cin >> N >> M >> S;

    int left = 0;
    // N日分のシャツの枚数があれば確実なため最大値
    int right = N;

    // 二部探索
    while (left < right)
    {
        int mid = (left + right) / 2;
        bool ans = check(mid);
        if (ans == false)
            left = mid + 1;
        if (ans == true)
            right = mid;
    }
    cout << left << endl;

    return 0;
}