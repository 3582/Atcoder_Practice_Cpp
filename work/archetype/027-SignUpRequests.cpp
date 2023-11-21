#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    // N 日間にわたる申請
    int N;
    cin >> N;

    // 登録済みのユーザ名を記録するハッシュテーブル
    unordered_set<string> ids;

    for (int i = 1; i <= N; ++i) // i 日目
    {
        // 申請されたユーザ名
        string id;
        cin >> id;

        if (ids.insert(id).second) // ユーザ名を新規登録できた場合
        {
            // 日にちを出力
            cout << i << '\n';
        }
    }
}