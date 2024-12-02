#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr)
{
    vector<int> sorted = arr, reversed = arr;
    sort(sorted.begin(), sorted.end());
    sort(reversed.begin(), reversed.end(), greater<int>());
    if (arr == sorted)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            int diff = abs(arr[i] - arr[i - 1]);
            if (diff < 1 or diff > 3)
                return false;
        }
        return true;
    }
    else if (arr == reversed)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            int diff = abs(arr[i] - arr[i - 1]);
            if (diff < 1 or diff > 3)
                return false;
        }
        return true;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int ans = 0;
    for (int i = 1; i <= 1000; i++)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num)
        {
            arr.push_back(num);
        }
        if (isValid(arr))
            ans++;
        else
        {
            for (int j = 0; j < arr.size(); j++)
            {
                vector<int> temp = arr;
                temp.erase(temp.begin() + j);
                if (isValid(temp))
                {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}