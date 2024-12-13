#include <bits/stdc++.h>
using namespace std;

int X, Y, a = -1, b = -1, c, d;

long long find_minimum_cost()
{
    long long new_X = X, new_Y = Y;
    new_X += 10000000000000;
    new_Y += 10000000000000;
    long long numerator = abs(new_X * d * 1LL - new_Y * c * 1LL);
    long long denominator = abs(a * d - b * c);
    if (numerator % denominator != 0)
    {
        return LLONG_MAX;
    }
    long long x = numerator / denominator;
    numerator = abs(new_X * b * 1LL - new_Y * a * 1LL);
    if (numerator % denominator != 0)
    {
        return LLONG_MAX;
    }
    long long y = numerator / denominator;
    return 3 * x + y;
}

void solve()
{
    string line;
    long long ans = 0;
    while (getline(cin, line))
    {
        if (line.empty())
        {
            long long min_cost = find_minimum_cost();
            // cout << min_cost << endl;
            min_cost != LLONG_MAX ? ans += min_cost : ans += 0;
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