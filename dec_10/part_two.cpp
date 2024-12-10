#include <bits/stdc++.h>
using namespace std;

vector<string> grid;

int getPaths(int x, int y, char ch)
{
    if (x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size())
        return 0;
    if (grid[x][y] == '9' and ch == '9')
    {
        return 1;
    }
    if (grid[x][y] == ch)
    {
        int ans = 0;
        char newCh = char(ch + 1);
        ans += getPaths(x + 1, y, newCh);
        ans += getPaths(x - 1, y, newCh);
        ans += getPaths(x, y + 1, newCh);
        ans += getPaths(x, y - 1, newCh);
        return ans;
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    vector<string> input;
    string s;
    while (getline(cin, s))
    {
        input.push_back(s);
    }
    grid = input;
    vector<pair<int, int>> CoordinatesOfZero;

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            if (input[i][j] == '0')
            {
                CoordinatesOfZero.push_back({i, j});
            }
        }
    }

    int ans = 0;

    for (auto it : CoordinatesOfZero)
    {
        grid = input;
        int cnt = getPaths(it.first, it.second, '0');
        ans += cnt;
    }
    cout << ans << endl;
}