// TODO

// #include <iostream>
// #include <string>
// #include <vector>
// #include <utility>

// using namespace std;

// int main()
// {
//     string S;
//     cin >> S;
//     vector<pair<int, char>> positions;
//     for (int i = 0; i < S.size(); i++)
//     {
//         positions.push_back(make_pair(i, S[i]));
//     }
//     int used = 0;
//     int unknown = 0;
//     vector<int> int_used;
//     vector<int> int_unknown;
//     for (auto &p : positions)
//     {
//         if (p.second == 'o')
//         {
//             used++;
//             int_used.push_back(p.first);
//         }
//         if (p.second == '?')
//         {
//             unknown++;
//             int_unknown.push_back(p.first);
//         }
//     }
//     if (used >= 5 || unknown + used == 0)
//     {
//         cout << 0 << endl;
//         return 0;
//     }
//     int ans = 0;
//     for (int i = 0; i < 10000; i++)
//     {
//         string str = to_string(i);
//         while (str.length() < 4)
//         {
//             str = "0" + str;
//         }

//         bool found = false;
//         for (int i_used : int_used)
//         {
//             if (str.find(to_string(i_used)) != string::npos)
//             {
//                 found = true;
//             }
//             else
//             {
//                 found = false;
//                 break;
//             }
//         }
//         if (!found)
//             continue;

//         bool unknown_used = true;
//         if (4 - int_used.size() > 0)
//         {
//             for (int i_unknown : int_unknown)
//             {
//                 if (str.find(to_string(i_unknown)) != string::npos)
//                 {
//                     unknown_used = true;
//                     break;
//                 }
//             }
//         }

//         if (unknown_used == 4 - int_used.size())
//         {
//             found = true;
//         }
//         else
//         {
//             found = false;
//         }

//         if (found)
//             ans++;
//     }

//     cout << ans << endl;

//     return 0;
// }
