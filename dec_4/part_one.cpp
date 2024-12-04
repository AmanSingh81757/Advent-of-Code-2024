#include <bits/stdc++.h>
using namespace std;

int checkForXmas(int i, int j, vector<string> &grid, int x, int y)
{
    string curr = "";
    int m = grid[0].size(), n = grid.size(), len = 0;

    while (i >= 0 && i < n && j >= 0 && j < m and len < 4)
    {
        curr += grid[i][j];
        i += x;
        j += y;
        len++;
    }
    return curr == "XMAS";
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
            if (grid[i][j] == 'X')
            {
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        if (k == 0 and l == 0)
                            continue;
                        ans += checkForXmas(i, j, grid, k, l);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}