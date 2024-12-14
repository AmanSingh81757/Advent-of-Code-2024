#include <bits/stdc++.h>
using namespace std;

int width = 101, height = 103;

void print(map<pair<int, int>, int> position_count)
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (position_count[{j, i}] > 0)
                cout << position_count[{j, i}];
            else
                cout << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < width; i++)
        cout << "-";
    for (int i = 0; i < width; i++)
        cout << "-";
}

void check_if_mirror(vector<vector<int>> &position_and_velocity)
{
    map<pair<int, int>, int> position_count;
    for (auto &pos : position_and_velocity)
    {
        position_count[{pos[0], pos[1]}]++;
    }
    if (position_count.size() == 500)
    {
        cout << "ans is: ";
    }
    // print(position_count);
}

void solve()
{
    string line;
    vector<vector<int>> position_and_velocity;
    vector<int> quadrant_count(4, 0);
    while (getline(cin, line))
    {
        int x, y, vx, vy;
        sscanf(line.c_str(), "p=%d,%d v=%d,%d", &x, &y, &vx, &vy);
        position_and_velocity.push_back({x, y, vx, vy});
    }
    int i = 0, cnt = 0;
    while (++i)
    {
        for (auto &pos : position_and_velocity)
        {
            pos[0] += (pos[2]);
            pos[0] += width;
            pos[0] %= width;
            pos[1] += (pos[3]);
            pos[1] += height;
            pos[1] %= height;
        }
        check_if_mirror(position_and_velocity);
        if (i > 6440 and i < 6450)
        {
            cout<<i<<endl;
            map<pair<int, int>, int> position_count;
            for (auto &pos : position_and_velocity)
            {
                position_count[{pos[0], pos[1]}]++;
            }
            print(position_count);
        }
        if (i > 10000)
            break;
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