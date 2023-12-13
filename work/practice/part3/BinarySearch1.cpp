#include <iostream>
using namespace std;

int N, X, A[100000];

// int search(int x)
// {
//     int left = 1;
//     int right = N;
//     while (left <= right)
//     {
//         int middle = (left + right) / 2;
//         if (x < A[middle])
//             right = middle - 1;
//         if (x == A[middle])
//             return middle;
//         if (x > A[middle])
//             left = middle + 1;
//     }
//     // exception
//     return -1;
// }

int main()
{
    cin >> N >> X;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    int *ans = lower_bound(A, A + N + 1, X);

    cout << ans - A << endl;
    return 0;
}