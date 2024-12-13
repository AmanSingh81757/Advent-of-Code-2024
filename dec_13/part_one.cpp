#include <bits/stdc++.h>
using namespace std;

int X, Y, a = -1, b = -1, c, d;

int find_minimum_cost()
{
    // cout << X << " " << Y << " " << a << " " << b << " " << c << " " << d << endl;
    int min_cost = INT_MAX;
    for (int i = 1; i <= 100;i++){
        int curr_x = a * i;
        int curr_y = b * i;
        int rem_x = X - curr_x;
        int rem_y = Y - curr_y;
        if(rem_x % c == 0 && rem_y % d == 0){
            int j = rem_x / c;
            int k = rem_y / d;
            if(j == k and j<=100 and j>=1){
                min_cost = min(min_cost, 3*i + j);
            }
        }
    }
    return min_cost;
}

void solve()
{
    string line;
    int ans = 0;
    while (getline(cin, line))
    {
        if (line.empty()){
            int min_cost = find_minimum_cost();
            min_cost != INT_MAX ? ans+=min_cost : ans+=0;
            a = b = c = d = -1;
            continue;
        }
        int pos_of_comma = line.find(',');
        if (line.substr(0, 6) == "Button")
        {
            int pos_of_plus = line.find('+');
            int x = stoi(line.substr(pos_of_plus, pos_of_comma - pos_of_plus));
            pos_of_plus = line.find('+', pos_of_comma);
            int y = stoi(line.substr(pos_of_plus, line.size() - pos_of_plus));
            if (a == -1)
            {
                a = x;
                b = y;
            }
            else
            {
                c = x;
                d = y;
            }
        }
        else
        {
            int pos_of_equal = line.find('=');
            X = stoi(line.substr(pos_of_equal + 1, pos_of_comma - pos_of_equal));
            pos_of_equal = line.find('=', pos_of_comma);
            Y = stoi(line.substr(pos_of_equal + 1, line.size() - pos_of_equal));
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