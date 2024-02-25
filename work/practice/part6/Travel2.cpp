#include <iostream>
using namespace std;

long long N, M, B;
long long A[200009], C[200009];

int main()
{
    cin >> N >> M >> B;
    for (long long i = 1; i <= N; i++)
        cin >> A[i];
    for (long long i = 1; i <= M; i++)
        cin >> C[i];

    long long A_sum = 0;
    long long C_sum = 0;
    for (long long i = 1; i <= N; i++)
        A_sum += A[i] * M;
    for (long long i = 1; i <= M; i++)
        C_sum += C[i] * N;

    cout << A_sum + B * N * M + C_sum << endl;
    return 0;
}