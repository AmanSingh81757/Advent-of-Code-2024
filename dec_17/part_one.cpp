#include <bits/stdc++.h>
using namespace std;
#define int long long

class Register
{
public:
    int value;
    Register()
    {
        value = 0;
    }
    Register(int v)
    {
        value = v;
    }
};

Register A, B, C;

void printRegisters()
{
    cout << "A: " << A.value << " B: " << B.value << " C: " << C.value << endl;
}

int comboValue(int operand)
{
    if (operand <= 3)
        return operand;
    else if (operand == 4)
        return A.value;
    else if (operand == 5)
        return B.value;
    else if (operand == 6)
        return C.value;
    else
        return 0;
}

void solve()
{
    string register_string, register_name;
    int value;
    for (int i = 0; i < 3; i++)
    {
        cin >> register_string >> register_name >> value;
        if (register_name[0] == 'A')
        {
            A.value = value;
        }
        else if (register_name[0] == 'B')
        {
            B.value = value;
        }
        else if (register_name[0] == 'C')
        {
            C.value = value;
        }
    }

    string program;
    cin >> program;

    string numbers;
    cin >> numbers;
    vector<int> program_numbers;

    int i = 0;
    while (i < numbers.size())
    {
        int opCode = numbers[i] - '0';
        int operand = numbers[i + 2] - '0';
        program_numbers.push_back(opCode);
        program_numbers.push_back(operand);
        i += 4;
    }
    i = 0;
    string ans = "";
    while (i < program_numbers.size() - 1)
    {
        int opCode = program_numbers[i], operand = program_numbers[i + 1];
        switch (opCode)
        {
        case 0:
            A.value = A.value / pow(2, operand);
            break;

        case 1:
            B.value = B.value ^ operand;
            break;

        case 2:
            B.value = comboValue(operand) % 8;
            break;

        case 3:
            if (A.value == 0)
            {
                break;
            }
            else
            {
                i = operand;
                continue;
            }

        case 4:
            B.value = B.value ^ C.value;
            break;

        case 5:
            if (ans.size() == 0)
                ans += to_string(comboValue(operand) % 8);
            else
                ans += "," + to_string(comboValue(operand) % 8);
            break;

        case 6:
            B.value = A.value / pow(2, comboValue(operand));
            break;

        case 7:
            C.value = A.value / pow(2, comboValue(operand));
            break;

        default:
            break;
        }
        i += 2;
    }
    cout << ans << endl;
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