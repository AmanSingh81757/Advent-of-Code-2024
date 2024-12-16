#include <bits/stdc++.h>
using namespace std;

vector<string> grid;

void solve()
{
    vector<string> input;
    int f = 0;
    string line;
    while (getline(cin, line))
    {
        input.push_back(line);
    }
    int start_x = 0, start_y = 0, end_x = 0, end_y = 0, n = input.size(), m = input[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (input[i][j] == 'S')
            {
                start_x = i;
                start_y = j;
            }
            if (input[i][j] == 'E')
            {
                end_x = i;
                end_y = j;
            }
        }
    }
    grid = input;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int dir_x = 0, dir_y = 1;
    pq.push({0, start_x, start_y, dir_x, dir_y});
    map<vector<int>, int> visited;
    visited[{start_x, start_y, dir_x, dir_y}] = 1;

    while (!pq.empty())
    {
        vector<int> top = pq.top();
        pq.pop();

        int cost = top[0], x = top[1], y = top[2], dir_x = top[3], dir_y = top[4];
        visited[{x, y, dir_x, dir_y}] = 1;

        if (x == end_x and y == end_y)
        {
            cout << cost << endl;
            return;
        }

        vector<pair<int, int>> options = {{dir_x, dir_y}, {dir_y, -dir_x}, {-dir_y, dir_x}};
        for (auto it : options)
        {
            int new_dir_x = it.first, new_dir_y = it.second;
            int new_x = x + new_dir_x, new_y = y + new_dir_y;
            if (new_x < 0 or new_x >= n or new_y < 0 or new_y >= m or grid[new_x][new_y] == '#')
            {
                continue;
            }
            if (visited.find({new_x, new_y, new_dir_x, new_dir_y}) != visited.end())
            {
                continue;
            }
            int extraCost;
            if (dir_x == new_dir_x and dir_y == new_dir_y)
                extraCost = 1;
            else
                extraCost = 1001;
            pq.push({cost + extraCost, new_x, new_y, new_dir_x, new_dir_y});
        }
    }
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    solve();

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Time: " << cpu_time_used << endl;
}