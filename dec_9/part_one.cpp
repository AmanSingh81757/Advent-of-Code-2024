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
    map<int, char> dots;
    int curr = 0, index = 0;
    for (int i = 0; i < line.size(); i++)
    {
        int num = line[i] - '0';
        if (i % 2 == 0)
        {
            for (int j = index; j < index + num; j++)
            {
                chars[j] = curr;
            }
            curr++;
            index += num;
        }
        else
        {
            for (int j = index; j < index + num; j++)
            {
                dots[j] = '.';
            }
            index += num;
        }
    }
    auto r = chars.end();
    r--;
    auto l = dots.begin();
    while (l != dots.end())
    {
        int dot_index = l->first;
        int char_index = r->first;
        if (char_index < dot_index)
        {
            break;
        }
        int num = r->second;
        chars[char_index] = 0;
        chars[dot_index] = num;
        l++;
        r--;
    }
    for (auto i : chars)
    {
        ans += i.second * 1LL * i.first;
    }
    cout << ans << endl;
}
