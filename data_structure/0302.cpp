#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
int calculate(int num1, int num2, int op)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string exp;
        cin >> exp;
        stack<int> nums;
        stack<char> ops;
        for (int j = 0; j < exp.length(); j++)
        {
            if (exp[j] >= '0' && exp[j] <= '9')
            {
                int k = j;
                int num = 0;
                for (; exp[k] >= '0' && exp[k] <= '9'; k++)
                {
                    num = num * 10 + exp[k] - '0';
                }
                nums.push(num);
                j = k - 1;
            }
            if (exp[j] == '(')
            {
                ops.push('(');
                continue;
            }
            if (exp[j] == ')')
            {
                while (!ops.empty() && ops.top() != '(')
                {
                    char op = ops.top();
                    ops.pop();
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    int result = calculate(num2, num1, op);
                    nums.push(result);
                }
                if (!ops.empty()) ops.pop();
            }
            if (exp[j] == '+' || exp[j] == '-')
            {
                while (!ops.empty() && !(ops.top() == '('))
                {
                    char op = ops.top();
                    ops.pop();
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    int result = calculate(num2, num1, op);
                    nums.push(result);
                }
                ops.push(exp[j]);
            }
            if (exp[j] == '*' || exp[j] == '/')
            {
                while (!ops.empty() && (ops.top() == '*' || ops.top() == '/'))
                {
                    char op = ops.top();
                    ops.pop();
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    int result = calculate(num2, num1, op);
                    nums.push(result);
                }
                ops.push(exp[j]);
            }
        }
        while (!ops.empty())
        {
            char op = ops.top();
            ops.pop();
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            int result = calculate(num2, num1, op);
            nums.push(result);
        }
        int result = nums.top();
        cout << result << endl;
    }
    return 0;
}