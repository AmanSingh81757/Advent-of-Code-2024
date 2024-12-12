#include <bits/stdc++.h>
using namespace std;

vector<string> grid;

pair<int, int> find_area(int i, int j, vector<vector<int>> &visited, char ch)
{
    int area = 1, corner = 0;
    visited[i][j] = 1;

    char up = i - 1 >= 0 ? grid[i - 1][j] : ' ';
    char down = i + 1 < grid.size() ? grid[i + 1][j] : ' ';
    char left = j - 1 >= 0 ? grid[i][j - 1] : ' ';
    char right = j + 1 < grid[0].size() ? grid[i][j + 1] : ' ';
    char up_left = i - 1 >= 0 and j - 1 >= 0 ? grid[i - 1][j - 1] : ' ';
    char up_right = i - 1 >= 0 and j + 1 < grid[0].size() ? grid[i - 1][j + 1] : ' ';
    char down_left = i + 1 < grid.size() and j - 1 >= 0 ? grid[i + 1][j - 1] : ' ';
    char down_right = i + 1 < grid.size() and j + 1 < grid[0].size() ? grid[i + 1][j + 1] : ' ';

    if(up != ch and right != ch){
        corner++;
    }
    if(down != ch and right != ch){
        corner++;
    }
    if(up != ch and left != ch){
        corner++;
    }
    if(down != ch and left != ch){
        corner++;
    }

    if(up == ch and right == ch and up_right != ch){
        corner++;
    }
    if(down == ch and right == ch and down_right != ch){
        corner++;
    }
    if(up == ch and left == ch and up_left != ch){
        corner++;
    }
    if(down == ch and left == ch and down_left != ch){
        corner++;
    }

    if(up == ch and visited[i - 1][j] == 0)
    {
        pair<int, int> pr = find_area(i - 1, j, visited, ch);
        area += pr.first;
        corner += pr.second;
    }
    if(down == ch and visited[i + 1][j] == 0)
    {
        pair<int, int> pr = find_area(i + 1, j, visited, ch);
        area += pr.first;
        corner += pr.second;
    }
    if(left == ch and visited[i][j - 1] == 0)
    {
        pair<int, int> pr = find_area(i, j - 1, visited, ch);
        area += pr.first;
        corner += pr.second;
    }
    if(right == ch and visited[i][j + 1] == 0)
    {
        pair<int, int> pr = find_area(i, j + 1, visited, ch);
        area += pr.first;
        corner += pr.second;
    }
    return {area, corner};

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
                pair<int, int> pr = find_area(i, j, visited, input[i][j]);
                int area = pr.first, corner = pr.second;
                ans += corner*area;
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