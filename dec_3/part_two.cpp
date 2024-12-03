#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int ans = 0;

    string line;
    bool isAllowed = true;
    while (getline(cin, line))
    {
        int l = 0, n = line.size();

        for (int i = 0; i < n; i++)
        {
            bool dontFound = line.substr(i, 7) == "don't()";
            if (dontFound)
            {
                isAllowed = false;
                continue;
            }

            bool doFound = line.substr(i, 4) == "do()";
            if (doFound)
            {
                isAllowed = true;
                continue;
            }

            if (!isAllowed)
                continue;

            bool isMul = line.substr(i, 4) == "mul(";
            if (!isMul)
                continue;

            int left_num = 0, right_num = 0, j = i + 4;

            while (line[j] >= '0' and line[j] <= '9')
            {
                left_num = left_num * 10 + (line[j] - '0');
                j++;
            }

            if (line[j] != ',')
                continue;

            j++;

            while (line[j] >= '0' and line[j] <= '9')
            {
                right_num = right_num * 10 + (line[j] - '0');
                j++;
            }

            if (line[j] != ')')
                continue;

            ans += left_num * right_num;
        }
    }
    cout << ans << endl;
}