#include <bits/stdc++.h>
using namespace std;

int width = 101, height = 103;

pair<int, int> find_position(int x, int y, int vx, int vy)
{
    int curr_x = x, curr_y = y;
    for (int i = 0; i < 100; i++)
    {
        curr_x += vx;
        curr_y += vy;
        curr_x += width;
        curr_y += height;
        curr_x %= width;
        curr_y %= height;
    }
    return {curr_x, curr_y};
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
        pair<int, int> final_position = find_position(x, y, vx, vy);
        int final_x = final_position.first, final_y = final_position.second;
        // cout<<final_x<<" "<<final_y<<endl;
        if (final_x < width / 2 && final_y < height / 2)
        {
            quadrant_count[0]++;
        }
        else if (final_x > width / 2 && final_y < height / 2)
        {
            quadrant_count[1]++;
        }
        else if (final_x < width / 2 && final_y > height / 2)
        {
            quadrant_count[2]++;
        }
        else if(final_x > width / 2 && final_y > height / 2)
        {
            quadrant_count[3]++;
        }
    }
    long long product = 1LL * quadrant_count[0] * quadrant_count[1] * quadrant_count[2] * quadrant_count[3];
    cout << product << endl;
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