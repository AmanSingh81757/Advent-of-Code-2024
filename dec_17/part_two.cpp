#include <bits/stdc++.h>
using namespace std;

#define int long long

// B = A % 8
// B = B ^ 1
// C = A >> B
// B = B ^ C
// A = A >> 3
// B = B ^ 6
// OUT(B % 8)
// IF A != 0 GOTO 0

// For A = 7:
// A = 0, B = 0, C = 0


vector<int> solveForA(int r, vector<int> program_numbers)
{
    if (r == program_numbers.size())
    {
        return {0};
    }
    vector<int> values_of_A = solveForA(r + 1, program_numbers);
    vector<int> possible_answers;
    for (auto value_A : values_of_A)
    {
        value_A <<= 3;
        for (int i = 0; i < 8; i++)
        {
            int curr_a = value_A + i;
            int curr_b = curr_a % 8;
            curr_b = curr_b ^ 1;
            int curr_c = curr_a >> curr_b;
            curr_b = curr_b ^ curr_c;
            curr_b = curr_b ^ 6;
            if (curr_b % 8 == program_numbers[r])
            {
                possible_answers.push_back(curr_a);
            }
        }
    }
    return possible_answers;
}

void solve()
{
    string register_string, register_name;
    int value;
    for (int i = 0; i < 3; i++)
    {
        cin >> register_string >> register_name >> value;
    }

    string program;
    cin >> program;

    string numbers;
    cin >> numbers;
    vector<int> program_numbers;

    int i = 0;
    while (i < numbers.size())
    {
        program_numbers.push_back(numbers[i] - '0');
        i += 2;
    }

    int r = 0;

    vector<int> answers = solveForA(r, program_numbers);
    cout << *min_element(answers.begin(), answers.end()) << endl;
}

signed main()
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