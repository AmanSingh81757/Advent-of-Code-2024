#include <bits/stdc++.h>
using namespace std;

vector<string> grid;

int find_area(int i, int j, vector<vector<int>> &visited, char ch)
{
    int n = grid.size(), m = grid[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] != ch)
    {
        return 0;
    }
    visited[i][j] = 1;
    int area = 1;
    area += find_area(i + 1, j, visited, ch);
    area += find_area(i - 1, j, visited, ch);
    area += find_area(i, j + 1, visited, ch);
    area += find_area(i, j - 1, visited, ch);
    return area;
}

void find_perimeter(int i, int j, vector<vector<int>> &visited, char ch, int &total)
{
    int n = grid.size(), m = grid[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] != ch)
    {
        return;
    }
    visited[i][j] = 1;
    int perimeter = 4;
    int number_of_neighbours = 0;
    if (i + 1 < n && visited[i + 1][j] and grid[i + 1][j] == ch)
    {
        number_of_neighbours++;
    }
    if (i - 1 >= 0 && visited[i - 1][j] and grid[i - 1][j] == ch)
    {
        number_of_neighbours++;
    }
    if (j + 1 < m && visited[i][j + 1] and grid[i][j + 1] == ch)
    {
        number_of_neighbours++;
    }
    if (j - 1 >= 0 && visited[i][j - 1] and grid[i][j - 1] == ch)
    {
        number_of_neighbours++;
    }
    if (number_of_neighbours == 4)
        perimeter -= 8;
    else if (number_of_neighbours == 3)
        perimeter -= 6;
    else if (number_of_neighbours == 2)
        perimeter -= 4;
    else if (number_of_neighbours == 1)
        perimeter -= 2;
    total += perimeter;
    find_perimeter(i + 1, j, visited, ch, total);
    find_perimeter(i - 1, j, visited, ch, total);
    find_perimeter(i, j + 1, visited, ch, total);
    find_perimeter(i, j - 1, visited, ch, total);
}

void solve()
{
    vector<string> input;
    string line;
    while (getline(cin, line))
    {
        input.push_back(line);
    }
    int n = input.size(), m = input[0].size();
    int ans = 0;
    grid = input;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> visited2(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                int total = 0;
                find_perimeter(i, j, visited2, grid[i][j], total);
                int area = find_area(i, j, visited, grid[i][j]);
                ans += total*area;
            }
        }
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