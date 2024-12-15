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

bool canMoveUpDown(int x, int y, int dir)
{
    if (grid[x + dir][y] == '#')
        return false;
    else if (grid[x + dir][y] == '.')
        return true;
    else if (grid[x + dir][y] == ']')
    {
        if (canMoveUpDown(x + dir, y, dir) and canMoveUpDown(x + dir, y - 1, dir))
            return true;
        return false;
    }
    else
    {
        if (canMoveUpDown(x + dir, y, dir) and canMoveUpDown(x + dir, y + 1, dir))
            return true;
        return false;
    }
}

void moveUpDown(int x, int y, int dir)
{
    if (grid[x + dir][y] == '.')
    {
        char ch = grid[x][y];
        grid[x][y] = '.';
        grid[x + dir][y] = ch;
    }
    else if (grid[x + dir][y] == '[')
    {
        moveUpDown(x + dir, y, dir);
        moveUpDown(x + dir, y + 1, dir);
        char ch = grid[x][y];
        grid[x][y] = '.';
        grid[x + dir][y] = ch;
    }
    else if (grid[x + dir][y] == ']')
    {
        moveUpDown(x + dir, y, dir);
        moveUpDown(x + dir, y - 1, dir);
        char ch = grid[x][y];
        grid[x][y] = '.';
        grid[x + dir][y] = ch;
    }
}

void moveLeftRight(int direction, int &x, int &y)
{
    if (grid[x][y + direction] == '.')
    {
        grid[x][y] = '.';
        y += direction;
        grid[x][y] = '@';
    }
    else if (grid[x][y + direction] == '#')
    {
        return;
    }
    else
    {
        int ny = y + direction;
        while (ny >= 0 and ny < m)
        {
            ny += direction;
            if(grid[x][ny] == '#') return;
            else if(grid[x][ny] == '.'){
                if(direction == 1){
                    for (int i = ny; i > y;i--){
                        grid[x][i] = grid[x][i - 1];
                    }
                    grid[x][y] = '.';
                    y++;
                    grid[x][y] = '@';
                }
                else{
                    for (int i = ny; i < y;i++){
                        grid[x][i] = grid[x][i + 1];
                    }
                    grid[x][y] = '.';
                    y--;
                    grid[x][y] = '@';
                }
                break;
            }
        }
    }
}

void simulate(int x, int y, string moves)
{

    for (char move : moves)
    {
        if (move == '<')
        {
            moveLeftRight(-1, x, y);
        }
        else if (move == '>')
        {
            moveLeftRight(1, x, y);
        }
        else if (move == 'v')
        {
            if (canMoveUpDown(x, y, 1))
            {
                moveUpDown(x, y, 1);
                x++;
            }
        }
        else if (move == '^')
        {
            if (canMoveUpDown(x, y, -1))
            {
                moveUpDown(x, y, -1);
                x--;
            }
        }
    }
}

void modifyInput(vector<string> &input)
{
    string line;
    while (getline(cin, line))
    {
        if (line == "")
            break;
        string modified_line = "";
        for (char ch : line)
        {
            if (ch == '#' or ch == '.')
            {
                modified_line += ch;
                modified_line += ch;
            }
            else if (ch == 'O')
            {
                modified_line += "[]";
            }
            else
            {
                modified_line += ch;
                modified_line += '.';
            }
        }
        input.push_back(modified_line);
    }
}

void solve()
{
    vector<string> input;
    int f = 0;
    modifyInput(input);
    string moves;
    string move;
    while (getline(cin, move))
    {
        moves += move;
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
            if (grid[i][j] == '[')
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