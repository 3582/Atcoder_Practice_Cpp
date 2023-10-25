#include <iostream>
using namespace std;

long long ans_a, ans_b;
long long X, Y, A[200], B[200], C[1000], D[1000];

bool matchFunc(long long move_x, long long move_y)
{
    bool match = false;
    for (int i = 1; i <= X; i++)
    {
        match = false;
        for (int j = 1; j <= Y; j++)
        {
            if (A[i] + move_x == C[j] && B[i] + move_y == D[j])
                match = true;
            if (match)
                break;
        }
        if (!match)
            break;
    }
    return match;
}

int move()
{
    long long move_x, move_y = 0;
    for (int i = 1; i <= X; i++)
    {
        for (int j = 1; j <= Y; j++)
        {
            move_x = C[j] - A[i];
            move_y = D[j] - B[i];

            bool match = matchFunc(move_x, move_y);
            if (match)
            {
                cout << move_x << " " << move_y << endl;
                return 0;
            }
        }
    }
    return 0;
}

int main()
{
    cin >> X;
    for (int i = 1; i <= X; i++)
        cin >> A[i] >> B[i];
    cin >> Y;
    for (int i = 1; i <= Y; i++)
        cin >> C[i] >> D[i];
    move();
    return 0;
}
