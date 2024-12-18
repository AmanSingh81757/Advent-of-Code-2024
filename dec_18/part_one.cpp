#include <bits/stdc++.h>
using namespace std;

int n = 70;
int times = 1024;

void printGrid(map<pair<int, int>, int> point_map)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (point_map[{i, j}] == 1)
            {
                cout << "#";
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
}

void solve()
{
    string line;
    vector<pair<int, int>> points;
    map<pair<int, int>, int> point_map;
    while (getline(cin, line))
    {
        int x = stoi(line.substr(0, line.find(',')));
        int y = stoi(line.substr(line.find(',') + 1));
        points.push_back({y, x});
    }
    for (int i = 0; i < times; i++)
    {
        point_map[points[i]] = 1;
    }
    queue<vector<int>> q;
    q.push({0, 0, 0});
    vector<vector<int>> visited(n + 1, vector<int>(n + 1, 0));
    visited[0][0] = 1;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!q.empty())
    {
        int x, y, d;
        vector<int> v = q.front();
        x = v[0], y = v[1], d = v[2];
        if (x == n and y == n)
        {
            cout << d << endl;
            break;
        }
        q.pop();
        for (auto it : directions)
        {
            int nx = x + it[0], ny = y + it[1];
            if (nx < 0 or nx > n or ny < 0 or ny > n or visited[nx][ny] == 1 or point_map[{nx, ny}] == 1)
            {
                continue;
            }
            visited[nx][ny] = 1;
            q.push({nx, ny, d + 1});
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