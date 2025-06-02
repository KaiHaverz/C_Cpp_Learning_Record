#include<iostream>
using namespace std;

void bubbleSort(int a[], int n)
{ 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] < a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n; // 输入数组的大小
    int a[n]; // 声明数组
    for(int i = 0; i < n; i++)
    {
        cin >> a[i]; // 输入数组元素
    }
    
    bubbleSort(a, n); // 调用冒泡排序函数
    
    for(int i = 0; i < n; i++)
    {
        cout << a[i]; // 输出排序后的数组元素
        if(i != n - 1) cout << " "; // 输出空格，避免最后一个元素后有空格
    }
    
    cout << endl; // 输出换行符
    return 0;
}