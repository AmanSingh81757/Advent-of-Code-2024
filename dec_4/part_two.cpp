#include <bits/stdc++.h>
using namespace std;

int isValid(int i, int j, vector<string> &grid)
{
    string left = "", right = "";
    if (i > 0 and i < grid.size() - 1 and j > 0 and j < grid[0].size() - 1)
    {
        left += grid[i - 1][j - 1], right += grid[i - 1][j + 1];
        left += 'A', right += 'A';
        left += grid[i + 1][j + 1], right += grid[i + 1][j - 1];

        if ((left == "MAS" or left == "SAM") and (right == "SAM" or right == "MAS"))
            return 1;
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int ans = 0;
    vector<string> grid(140);
    for (int i = 0; i < 140; i++)
    {
        cin >> grid[i];
    }

    int m = grid[0].size(), n = grid.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                ans += (isValid(i, j, grid));
            }
        }
    }
    cout << ans << endl;
}