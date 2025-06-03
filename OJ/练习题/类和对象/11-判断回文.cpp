#include <iostream>
#include <cstring>
using namespace std;

class mystrcla
{
public:
    char str[101]; // 存放字符串
    int len;       // 字符串长度

    // 构造函数
    mystrcla(char *s)
    {
        strcpy(str, s);    // 复制输入字符串到成员变量
        len = strlen(str); // 计算字符串长度
    }

    // 输出字符串
    void strout()
    {
        cout << str << endl; // 直接输出存储的字符串
    }

    // 判断是否是回文串
    bool strIspal()
    {
        for (int i = 0; i < len / 2; i++)
        { // 只需要比较前半部分和后半部分
            if (str[i] != str[len - 1 - i])
            { // 前后对应位置字符不相同
                return false;
            }
        }
        return true; // 所有对应位置都相同
    }
};

int main()
{
    char input[101];
    cin.getline(input, 101); // 读取一行输入（最多100个字符）

    // 创建自定义字符串对象
    mystrcla mystr(input);

    // 输出字符串
    mystr.strout();

    // 判断并输出是否是回文串
    if (mystr.strIspal())
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}