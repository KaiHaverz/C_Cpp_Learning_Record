#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int q;
    cin >> q; // 查询个数

    while (q--)
    {
        int n;
        cin >> n; // 序列长度

        int pushed[n], poped[n];
        // 读取入栈序列
        for (int i = 0; i < n; i++)
        {
            cin >> pushed[i];
        }
        // 读取出栈序列
        for (int i = 0; i < n; i++)
        {
            cin >> poped[i];
        }

        stack<int> st; // 模拟栈
        int j = 0;     // 指向出栈序列的指针

        // 遍历入栈序列
        for (int i = 0; i < n; i++)
        {
            // 将当前元素入栈
            st.push(pushed[i]);

            // 检查栈顶元素是否等于出栈序列的当前元素
            while (!st.empty() && st.top() == poped[j])
            {
                st.pop(); // 匹配成功，弹出栈顶
                j++;      // 移动到下一个出栈元素
            }
        }

        // 判断是否所有元素都出栈
        if (j == n)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}