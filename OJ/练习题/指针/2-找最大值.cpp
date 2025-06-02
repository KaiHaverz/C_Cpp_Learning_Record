#include <iostream>
using namespace std;

int findMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}


int main()
{
    int n;
    cin >> n; // 输入数组的大小
    int a[n]; // 声明数组
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // 输入数组元素
    }

    int maxValue = findMax(a, n); // 调用函数查找最大值
    cout << maxValue << endl; // 输出最大值

    return 0;
}