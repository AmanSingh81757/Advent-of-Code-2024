#include <bits/stdc++.h>
using namespace std;

int start_x = 0, start_y = 0, start_direction_x = -1, start_direction_y = 0;

bool getNextCell(vector<string> &input, int x, int y, int direction_x, int direction_y)
{
    int next_x = x + direction_x;
    int next_y = y + direction_y;
    if (next_x < 0 || next_x >= input.size() || next_y < 0 || next_y >= input[0].size())
        return true;
    if (input[next_x][next_y] == '#')
        return false;
    return true;
}

void changeDirectionToRight(int &x, int &y)
{
    if (x == 0 && y == 1)
    {
        x = 1;
        y = 0;
    }
    else if (x == 1 && y == 0)
    {
        x = 0;
        y = -1;
    }
    else if (x == 0 && y == -1)
    {
        x = -1;
        y = 0;
    }
    else
    {
        x = 0;
        y = 1;
    }
}

void simulate(vector<string> &input, int x, int y, int direction_x, int direction_y)
{
    while (x >= 0 && x < input.size() && y >= 0 && y < input[0].size())
    {
        if (getNextCell(input, x, y, direction_x, direction_y))
        {
            input[x][y] = 'X';
            x += direction_x;
            y += direction_y;
        }
        else
        {
            changeDirectionToRight(direction_x, direction_y);
        }
        if (x == start_x && y == start_y and direction_x == start_direction_x and direction_y == start_direction_y)
            break;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    vector<string> input(130);
    int x, y;
    for (int i = 0; i < 130; i++)
    {
        cin >> input[i];
        for (int j = 0; j < input[i].size(); j++)
        {
            if (input[i][j] == '^')
            {
                x = i;
                y = j;
            }
        }
    }
    int direction_x = -1, direction_y = 0;
    start_x = x;
    start_y = y;
    start_direction_x = direction_x;
    start_direction_y = direction_y;
    simulate(input, x, y, direction_x, direction_y);
    int count = 0;
    for (int i = 0; i < 130; i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            if (input[i][j] == 'X')
                count++;
        }
    }
    cout << count << endl;
}