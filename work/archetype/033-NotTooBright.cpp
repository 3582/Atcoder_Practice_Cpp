#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    if ((H == 1) || (W == 1)) // 2x2 領域が存在しないコーナーケース
    {
        // 全部点灯
        cout << (H * W) << endl;
    }
    else
    {
        // 3 4 4
        // #..#
        // ....
        // #..#

        // 3 7 6
        // #..#..#
        // .......
        // #..#..#

        // 5 4 6
        // #..#
        // ....
        // #..#
        // ....
        // #..#

        cout << ((H + 1) / 2) * ((W + 1) / 2) << endl;
    }
    return 0;
}