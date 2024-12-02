#include <bits/stdc++.h>
using namespace std;

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
        while (ss >> num) {
            arr.push_back(num);
        }
        vector<int> sorted = arr, reversed = arr;
        sort(sorted.begin(), sorted.end());
        sort(reversed.begin(), reversed.end(), greater<int>());
        if(arr == sorted){
            int f = 1;
            for (int i = 1; i < arr.size();i++){
                int diff = abs(arr[i] - arr[i - 1]);
                if(diff < 1 or diff >3){
                    f = 0;
                    break;
                }
            }
            if(f)
            ans++;
        }
        else if(arr == reversed){
            int f = 1;
            for (int i = 1; i < arr.size();i++){
                int diff = abs(arr[i] - arr[i - 1]);
                if(diff < 1 or diff >3){
                    f = 0;
                    break;
                }
            }
            if(f)
            ans++;
        }
    }
    cout <<ans<< endl;
}