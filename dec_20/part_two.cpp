#include <bits/stdc++.h>
using namespace std;

vector<string> grid;
vector<vector<int>> distance_grid;
int n, m, start_x, start_y, end_x, end_y;

void print_grid()
{
    for (int i = 0; i < n; i++)
    {
        cout << grid[i] << endl;
    }
}

void print_distance_grid()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << distance_grid[i][j] << " ";
        }
        cout << endl;
    }
}

void mark_dis(int x, int y, int dis)
{
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#' || grid[x][y] == '*' || distance_grid[x][y] != -1)
        return;
    if (grid[x][y] == 'E')
    {
        distance_grid[x][y] = dis;
        return;
    }
    distance_grid[x][y] = dis;
    grid[x][y] = '*';
    mark_dis(x + 1, y, dis + 1);
    mark_dis(x - 1, y, dis + 1);
    mark_dis(x, y + 1, dis + 1);
    mark_dis(x, y - 1, dis + 1);
}

int getNextCells(int x, int y, int dx, int dy)
{
    if (x + dx < n and x + dx >= 0 and y + dy < m and y + dy >= 0 and distance_grid[x + dx][y + dy] != -1)
    {
        return distance_grid[x + dx][y + dy];
    }

    return 1000000;
}

void solve()
{
    vector<string> input;
    string line;
    while (getline(cin, line))
    {
        input.push_back(line);
    }
    grid = input;
    n = grid.size(), m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'S')
                start_x = i, start_y = j;
            else if (grid[i][j] == 'E')
                end_x = i, end_y = j;
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, -1));
    distance_grid = dist;
    int dis = 0;
    mark_dis(start_x, start_y, dis);
    // print_grid();
    // print_distance_grid();

    int initialDis = distance_grid[end_x][end_y];

    long long ans = 0;
    map<int, int> mp;
    vector<vector<int>> directions = {{0, 2}, {0, -2}, {2, 0}, {-2, 0}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (input[i][j] == '.' or input[i][j] == 'S')
            {
                for (int dx = 1; dx <= 20; dx++)
                {
                    for (int dy = 1; dy <= 20 - dx; dy++)
                    {
                        int nextCellDistance1 = getNextCells(i, j, dx, dy);
                        if (nextCellDistance1 != 1000000 and nextCellDistance1 > distance_grid[i][j] + dx + dy)
                            if (nextCellDistance1 - distance_grid[i][j] - dx - dy > 0)
                                mp[nextCellDistance1 - distance_grid[i][j] - dx - dy]++;

                        nextCellDistance1 = getNextCells(i, j, -dx, -dy);
                        if (nextCellDistance1 != 1000000 and nextCellDistance1 > distance_grid[i][j] + dx + dy)
                            if (nextCellDistance1 - distance_grid[i][j] - dx - dy > 0)
                                mp[nextCellDistance1 - distance_grid[i][j] - dx - dy]++;

                        nextCellDistance1 = getNextCells(i, j, dx, -dy);
                        if (nextCellDistance1 != 1000000 and nextCellDistance1 > distance_grid[i][j] + dx + dy)
                            if (nextCellDistance1 - distance_grid[i][j] - dx - dy > 0)
                                mp[nextCellDistance1 - distance_grid[i][j] - dx - dy]++;

                        nextCellDistance1 = getNextCells(i, j, -dx, dy);
                        if (nextCellDistance1 != 1000000 and nextCellDistance1 > distance_grid[i][j] + dx + dy)
                            if (nextCellDistance1 - distance_grid[i][j] - dx - dy > 0)
                                mp[nextCellDistance1 - distance_grid[i][j] - dx - dy]++;
                    }
                }
                for (int d = 1; d <= 20; d++)
                {
                    int nextCellDistance1 = getNextCells(i, j, d, 0);
                    if (nextCellDistance1 != 1000000 and nextCellDistance1 > distance_grid[i][j] + d)
                        if (nextCellDistance1 - distance_grid[i][j] - d > 0)
                            mp[nextCellDistance1 - distance_grid[i][j] - d]++;

                    nextCellDistance1 = getNextCells(i, j, -d, 0);
                    if (nextCellDistance1 != 1000000 and nextCellDistance1 > distance_grid[i][j] + d)
                        if (nextCellDistance1 - distance_grid[i][j] - d > 0)
                            mp[nextCellDistance1 - distance_grid[i][j] - d]++;

                    nextCellDistance1 = getNextCells(i, j, 0, d);
                    if (nextCellDistance1 != 1000000 and nextCellDistance1 > distance_grid[i][j] + d)
                        if (nextCellDistance1 - distance_grid[i][j] - d > 0)
                            mp[nextCellDistance1 - distance_grid[i][j] - d]++;

                    nextCellDistance1 = getNextCells(i, j, 0, -d);
                    if (nextCellDistance1 != 1000000 and nextCellDistance1 > distance_grid[i][j] + d)
                        if (nextCellDistance1 - distance_grid[i][j] - d > 0)
                            mp[nextCellDistance1 - distance_grid[i][j] - d]++;
                }
            }
        }
    }
    for (auto it : mp)
    {
        // cout << it.first << " " << it.second << endl;
        if (it.first >= 100)
            ans += it.second * 1LL;
    }
    cout << ans << endl;
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