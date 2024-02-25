#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;  // 入力を受け取る
    map<string, int> frequency;  // 文字列の頻度を保存するマップ
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;  // 文字列を受け取る
        frequency[s]++;  // 受け取った文字列の頻度を増やす
    }

    string mostFrequentString;  // 最も頻繁に出現する文字列を保存する変数
    int maxCount = 0;  // 最大の出現回数を保存する変数
    for (const auto &pair : frequency) {  // マップをループして最も頻繁に出現する文字列を見つける
        if (pair.second > maxCount) {  // 現在の最大出現回数よりも大きい場合
            maxCount = pair.second;  // 最大出現回数を更新
            mostFrequentString = pair.first;  // 最も頻繁に出現する文字列を更新
        }
    }

    cout << mostFrequentString << endl;  // 最も頻繁に出現する文字列を出力
    return 0;
}