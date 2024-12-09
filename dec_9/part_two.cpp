#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    string line;
    cin >> line;

    long long ans = 0;
    map<int, int> chars;
    vector<pair<int, int>> dots;
    vector<vector<int>> chars2;
    int curr = 0, index = 0;
    for (int i = 0; i < line.size(); i++)
    {
        int num = line[i] - '0';
        if (i % 2 == 0)
        {
            chars2.push_back({index, num, curr});
            for (int j = index; j < index + num; j++)
            {
                chars[j] = curr;
            }
            curr++;
            index += num;
        }
        else
        {
            if (num == 0)
                continue;
            dots.push_back({num, index});
            index += num;
        }
    }

    int r = chars2.size() - 1;
    int l = 0;

    while (r >= 0)
    {
        int char_length = chars2[r][1];
        int char_num = chars2[r][2];
        int char_index = chars2[r][0];
        int minn_index = INT_MAX, minn_index_length = INT_MAX;
        for (auto it : dots)
        {
            if (it.first >= char_length and it.second < char_index)
            {
                if (it.second < minn_index)
                {
                    minn_index = it.second;
                    minn_index_length = it.first;
                }
            }
        }
        if (minn_index == INT_MAX)
        {
            r--;
            continue;
        }
        for (auto it = dots.begin(); it != dots.end(); it++)
        {
            if (it->first == minn_index_length and it->second == minn_index)
            {
                dots.erase(it);
                break;
            }
        }

        for (int i = minn_index; i < minn_index + char_length; i++)
        {
            chars[i] = char_num;
        }
        for (int i = char_index; i < char_index + char_length; i++)
        {
            chars[i] = 0;
        }
        int remaining_dots = minn_index_length - char_length;
        dots.push_back({remaining_dots, minn_index + char_length});
        r--;
    }
    for (auto it : chars)
    {
        ans += it.second * 1LL * it.first;
    }

    cout << ans << endl;
}
