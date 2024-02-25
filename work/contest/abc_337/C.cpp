// TODO
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int ans = 0;
    int N;
    cin >> N;
    vector<std::pair<int, int>> index;
    for (int i = 1; i <= N; i++)
    {
        cin >> index[i].second;
        index[i].first = i;
    }

    vector<int> answer;
    for (int i = 1; i <= N; i++)
    {
        if (index[i].second == -1)
        {
            answer.push_back(index[i].first);
        }
    }

    for (const auto &elem : index)
    {
        cout << elem.first << " " << elem.second << endl;
    }

    cout << endl;

    return 0;
}