#include <iostream>
#include <cstring> // 添加缺失的头文件
using namespace std;

void stringZip(const char *pInputStr, int lInputLen, char *pOutputStr);

int main()
{
    char a[1000]; // 原始字符串
    cin >> a;
    int len = strlen(a); // 字符串长度
    char b[1000];        // 压缩后的字符串
    stringZip(a, len, b);
    cout << b << endl;
    return 0;
}

void stringZip(const char *pInputStr, int lInputLen, char *pOutputStr)
{
    // 如果输入为空字符串，直接返回空字符串
    if (lInputLen == 0)
    {
        *pOutputStr = '\0';
        return;
    }

    char *out = pOutputStr;    // 指向输出字符串的指针
    char current = *pInputStr; // 当前处理的字符
    int count = 1;             // 当前字符的连续计数

    // 从第二个字符开始遍历
    for (int i = 1; i < lInputLen; i++)
    {
        // 如果当前字符与前一个相同
        if (pInputStr[i] == current)
        {
            count++;
        }
        // 如果字符不同
        else
        {
            // 处理之前累计的字符
            if (count > 1)
            {
                *out++ = '0' + count;
            }
            *out++ = current;

            // 开始新的字符计数
            current = pInputStr[i];
            count = 1;
        }
    }

    // 处理字符串末尾的字符
    if (count > 1)
    {
        *out++ = '0' + count;
    }
    *out++ = current;

    // 添加字符串结束符
    *out = '\0';
}