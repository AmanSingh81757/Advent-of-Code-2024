#include <bits/stdc++.h>
#include <ctime>
using namespace std;

bool exploreCombinations(vector<long long> arr, int index, long long currentResult, long long result)
{
    if (index == arr.size())
    {
        return currentResult == result;
    }
    if(currentResult > result)
        return false;

    if (exploreCombinations(arr, index + 1, currentResult + arr[index], result))
        return true;

    if (exploreCombinations(arr, index + 1, currentResult * arr[index], result))
        return true;

    string combined = to_string(currentResult) + to_string(arr[index]);
    long long newResult = stoll(combined);
    if (combined.size() > to_string(result).size())
        return false;
    if (exploreCombinations(arr, index + 1, newResult, result))
        return true;
    return false;
}

bool getAllPossibleResults(vector<long long> arr, long long result)
{
    return exploreCombinations(arr, 1, arr[0], result);
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

    long long ans = 0;
    string s;
    for (int i = 0; i < 850; i++)
    {
        cin >> s;
        s.pop_back();
        long long res = stoll(s);
        long long num;
        vector<long long> arr;
        while (cin >> num)
        {
            arr.push_back(num);
            if (cin.peek() == '\n')
            {
                if (getAllPossibleResults(arr, res))
                {
                    ans += res;
                }
                break;
            }
        }
    }
    cout << ans << endl;

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Time: " << cpu_time_used << endl;
}