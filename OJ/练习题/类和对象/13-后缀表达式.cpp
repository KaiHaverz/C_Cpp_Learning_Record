#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string expr;
    getline(cin, expr); // 读取后缀表达式

    stack<int> st;            // 存储操作数的栈
    int num = 0;              // 用于构建多位数字
    bool buildingNum = false; // 标记是否正在构建数字

    for (char c : expr)
    {
        if (c == '@')
            break; // 遇到结束符号，退出循环

        if (isdigit(c))
        {
            // 处理数字字符
            num = num * 10 + (c - '0');
            buildingNum = true;
        }
        else if (c == '.')
        {
            // 数字结束，将完整数字压入栈
            if (buildingNum)
            {
                st.push(num);
                num = 0;
                buildingNum = false;
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            // 遇到运算符，从栈中取出两个操作数
            if (st.size() < 2)
            {
                cout << "错误：栈中操作数不足" << endl;
                return 1;
            }

            int right = st.top();
            st.pop(); // 右操作数（后弹出的）
            int left = st.top();
            st.pop(); // 左操作数（先弹出的）

            // 执行运算
            switch (c)
            {
            case '+':
                st.push(left + right);
                break;
            case '-':
                st.push(left - right);
                break;
            case '*':
                st.push(left * right);
                break;
            case '/':
                st.push(left / right);
                break;
            }
        }
    }

    // 输出最终结果
    if (!st.empty())
    {
        cout << st.top() << endl;
    }
    else
    {
        cout << "错误：无结果" << endl;
    }

    return 0;
}