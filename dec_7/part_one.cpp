#include <bits/stdc++.h>
using namespace std;

void exploreCombinations(vector<long long> arr, int index, long long currentResult, set<long long> &results)
{
    if (index == arr.size())
    {
        results.insert(currentResult);
        return;
    }

    exploreCombinations(arr, index + 1, currentResult + arr[index], results);
    exploreCombinations(arr, index + 1, currentResult * arr[index], results);
}

set<long long> getAllPossibleResults(vector<long long> arr)
{
    set<long long> results;
    exploreCombinations(arr, 1, arr[0], results);
    return results;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    long long ans = 0;
    string s;
    for (int i = 0; i < 850; i++)
    {
        cin >> s;
        s.pop_back();
        long long res = stoll(s);
        // cout << res << endl;
        long long num;
        vector<long long> arr;
        while (cin >> num)
        {
            arr.push_back(num);
            if (cin.peek() == '\n')
            {
                set<long long> results = getAllPossibleResults(arr);
                if(results.find(res) != results.end())
                    ans+=res;
                break;
            }
        }
    }
    cout << ans << endl;
}