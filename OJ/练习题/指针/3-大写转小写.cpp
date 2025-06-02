#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char str[101]; // 为字符串分配空间
    cin.getline(str, 101); // 读取一行输入，包括空格
    
    // 使用指针遍历字符串
    char *ptr = str;
    while (*ptr != '\0') {
        // 如果是小写字母，则转换为大写
        if (islower(*ptr)) {
            *ptr = toupper(*ptr);
        }
        ptr++; // 移动指针到下一个字符
    }
    
    // 输出转换后的字符串
    cout << str << endl;
    
    return 0;
}