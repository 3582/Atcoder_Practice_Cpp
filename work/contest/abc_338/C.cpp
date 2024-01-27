// TODO
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> q_N(N);
    vector<int> a_N(N);
    vector<int> b_N(N);
    for (int i = 0; i < N; i++)
        cin >> q_N[i];
    for (int i = 0; i < N; i++)
        cin >> a_N[i];
    for (int i = 0; i < N; i++)
        cin >> b_N[i];

    vector<int> a_count_vector(N);
    for (int i = 0; i < N; i++)
        a_count_vector[i] = q_N[i] / a_N[i];
    int max_count_a = a_count_vector[0];
    for (int i = 1; i < N; i++)
    {
        if (a_count_vector[i] < max_count_a)
        {
            max_count_a = a_count_vector[i];
        }
    }

    int max_dishes = 0;
    for (int a = 0; a <= max_count_a; ++a)
    {
        vector<int> material(N);
        for (int i = 0; i < N; i++)
        {
            material[i] = q_N[i] - a * a_N[i];
        }

        vector<int> b_count_vector(N);
        for (int i = 0; i < N; i++)
            b_count_vector[i] = material[i] / a_N[i];
            
        int max_count_b = b_count_vector[0];
        for (int i = 1; i < N; i++)
        {
            if (b_count_vector[i] < max_count_b)
            {
                max_count_b = b_count_vector[i];
            }
        }

        max_dishes = max(max_dishes, a + max_count_b);
    }
    cout << max_dishes << endl;
    return 0;
}