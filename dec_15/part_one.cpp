#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;

void printGrid()
{
    for (int i = 0; i < n; i++)
    {
        cout << grid[i] << endl;
    }
    cout << endl;
}

void simulate(int x, int y, string moves)
{

    for (char move : moves)
    {
        // printGrid();
        // cout << move << endl;
        if (move == '^')
        {
            if (grid[x - 1][y] == '#')
                continue;
            else if (grid[x - 1][y] == '.')
            {
                grid[x][y] = '.';
                x--;
                grid[x][y] = '@';
            }
            else
            {
                int nx = x - 1;
                while (nx >= 0 and grid[nx][y] == 'O')
                {
                    nx--;
                    if (grid[nx][y] == '#')
                    {
                        break;
                    }
                    else if (grid[nx][y] == '.')
                    {
                        grid[x][y] = '.';
                        x--;
                        grid[nx][y] = 'O';
                        grid[x][y] = '@';
                        break;
                    }
                }
            }
        }
        else if (move == 'v')
        {
            if (grid[x + 1][y] == '#')
                continue;
            else if (grid[x + 1][y] == '.')
            {
                grid[x][y] = '.';
                x++;
                grid[x][y] = '@';
            }
            else
            {
                int nx = x + 1;
                while (nx < n and grid[nx][y] == 'O')
                {
                    nx++;
                    if (grid[nx][y] == '#')
                    {
                        break;
                    }
                    else if (grid[nx][y] == '.')
                    {
                        grid[x][y] = '.';
                        x++;
                        grid[nx][y] = 'O';
                        grid[x][y] = '@';
                        break;
                    }
                }
            }
        }
        else if (move == '<')
        {
            if (grid[x][y - 1] == '#')
                continue;
            else if (grid[x][y - 1] == '.')
            {
                grid[x][y] = '.';
                y--;
                grid[x][y] = '@';
            }
            else
            {
                int ny = y - 1;
                while (ny >= 0 and grid[x][ny] == 'O')
                {
                    ny--;
                    if (grid[x][ny] == '#')
                    {
                        break;
                    }
                    else if (grid[x][ny] == '.')
                    {
                        grid[x][y] = '.';
                        y--;
                        grid[x][ny] = 'O';
                        grid[x][y] = '@';
                        break;
                    }
                }
            }
        }
        else if (move == '>')
        {
            if (grid[x][y + 1] == '#')
                continue;
            else if (grid[x][y + 1] == '.')
            {
                grid[x][y] = '.';
                y++;
                grid[x][y] = '@';
            }
            else
            {
                int ny = y + 1;
                while (ny < m and grid[x][ny] == 'O')
                {
                    ny++;
                    if (grid[x][ny] == '#')
                    {
                        break;
                    }
                    else if (grid[x][ny] == '.')
                    {
                        grid[x][y] = '.';
                        y++;
                        grid[x][ny] = 'O';
                        grid[x][y] = '@';
                        break;
                    }
                }
            }
        }
        // printGrid();
    }
}

void solve()
{
    vector<string> input;
    string line;
    int f = 0;
    while (getline(cin, line))
    {
        if (line == "")
            break;
        input.push_back(line);
    }
    string moves;
    string move;
    while(getline(cin, move)){
        moves+=move;
    }
    int x, y;
    n = input.size(), m = input[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (input[i][j] == '@')
                x = i, y = j;
        }
    }
    grid = input;
    simulate(x, y, moves);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'O')
            {
                int gps = 100 * i;
                gps += j;
                // cout<<gps<<endl;
                ans += gps;
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