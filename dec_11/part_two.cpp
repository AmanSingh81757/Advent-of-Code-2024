#include <bits/stdc++.h>
using namespace std;

map<pair<long long, int>, long long> mp;

long long number_of_stones(long long num, int level, int max_level)
{
    if (level == max_level)
    {
        return 1LL;
    }
    if (mp.find({num, level}) != mp.end())
    {
        return mp[{num, level}];
    }
    if (num == 0LL)
    {
        return mp[{num, level}] = number_of_stones(1LL, level + 1, max_level);
    }
    int number_of_digits = floor(log10(num) + 1);
    if (number_of_digits % 2 == 0)
    {
        long long div = 10;
        for (int i = 0; i < number_of_digits / 2 - 1; i++)
        {
            div *= 10;
        }
        long long left = num / div, right = num % div;
        return mp[{num, level}] = number_of_stones(left, level + 1, max_level) + number_of_stones(right, level + 1, max_level);
    }
    else
    {
        return mp[{num, level}] = number_of_stones(num * 2024 * 1LL, level + 1, max_level);
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

    long long num;
    long long total = 0;
    vector<long long> stones;
    while (cin >> num)
    {
        stones.push_back(num);
    }

    for (auto num : stones)
    {
        total += number_of_stones(num, 0, 75);
    }

    cout << total;

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Time: " << cpu_time_used << endl;
}