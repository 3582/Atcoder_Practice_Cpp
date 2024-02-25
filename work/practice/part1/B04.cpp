#include <iostream>
using namespace std;

int main() {
    string N;
    cin >> N;
    int decimalN = 0;
    int base = 1;

    for (int i = N.size() - 1; i >= 0; i--) {
        decimalN += (N[i] - '0') * base;
        base *= 2;
    }

    cout << decimalN << endl;
    return 0;
}
