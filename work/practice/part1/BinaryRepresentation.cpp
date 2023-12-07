#include <iostream>
#include <bitset>
using namespace std;
int main()
{
    int N;
    cin >> N;
    // N進法変換、10桁
    bitset<10> bs(N);
    cout << bs << endl;
    return 0;
}