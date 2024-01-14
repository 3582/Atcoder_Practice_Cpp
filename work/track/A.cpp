#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    unordered_map<string, vector<string>> start_map;
    unordered_map<string, bool> used;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        string first_char = s[i].substr(0, 3);
        start_map[first_char].push_back(s[i]);
        used[s[i]] = false;
    }

    string current_string = "り";
    int count = 0;
    bool can_finish = false;

    while (true)
    {
        bool found = false;
        if (start_map.find(current_string) != start_map.end())
        {
            for (const string &word : start_map[current_string])
            {
                if (!used[word])
                {
                    string last_char = word.substr(word.length() - 3);
                    if (last_char == "ん")
                    {
                        used[word] = true;
                        current_string = last_char;
                        count++;
                        found = true;
                        can_finish = true;
                        break;
                    }
                }
            }

            if (!found)
            {
                for (const string &word : start_map[current_string])
                {
                    if (!used[word])
                    {
                        used[word] = true;
                        current_string = word.substr(word.length() - 3);
                        count++;
                        found = true;
                        break;
                    }
                }
            }
        }
        if (!found)
        {
            can_finish = (current_string == "ん");
            break;
        }
    }

    cout << (can_finish ? count : -1) << endl;
    return 0;
}

// start_mapの内容を出力
// for (const auto &pair : start_map)
// {
//     cout << "Key: " << pair.first << " -> Values: ";
//     for (const auto &str : pair.second)
//     {
//         cout << str << " ";
//     }
//     cout << endl;
// }