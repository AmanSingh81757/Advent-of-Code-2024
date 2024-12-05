#include <bits/stdc++.h>
using namespace std;

vector<int> vectorFromLine(string &line)
{
    vector<int> result;
    stringstream ss(line);
    string temp;
    while (getline(ss, temp, ','))
    {
        result.push_back(stoi(temp));
    }
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    set<int> pages;

    map<pair<int, int>, int> pairs_map;

    string s;
    for (int i = 1; i <= 1176; i++)
    {
        cin >> s;

        string from_num_string = "", to_num_string = "";
        from_num_string += s[0], to_num_string += s[3];
        from_num_string += s[1], to_num_string += s[4];

        int from_num = stoi(from_num_string), to_num = stoi(to_num_string);

        pairs_map[{to_num, from_num}] = 1;
    }

    int ans = 0;

    string line;
    while (getline(cin, line))
    {
        if (line.size() == 0)
            continue;
        vector<int> update = vectorFromLine(line);
        int n = update.size();
        int flag = 1;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (pairs_map.find({update[i], update[j]}) != pairs_map.end())
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (!flag)
        {
            sort(update.begin(), update.end(), [&pairs_map](int a, int b)
                 {
                if(pairs_map.find({a, b}) != pairs_map.end()){
                    return true;
                }
                return false; });
            ans += update[n / 2];
        }
    }
    cout << ans << endl;
}