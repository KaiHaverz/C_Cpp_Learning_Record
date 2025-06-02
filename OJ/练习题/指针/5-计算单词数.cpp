#include<iostream>
using namespace std;

//编写一个函数,计算一个字符串中单词的个数
int countWords(const char *str) {
    int count = 0;
    bool inWord = false; // 标记是否在单词中

    while (*str) {
        if (*str == ' ') {
            inWord = false; // 遇到空格，标记为不在单词中
        } else {
            if (!inWord) {
                count++; // 遇到非空格且不在单词中，说明找到一个新单词
                inWord = true; // 标记为在单词中
            }
        }
        str++;
    }
    return count;
}

int main() {
    char str[1000];
    cin.getline(str, 1000); // 读取一行输入，包括空格
    int wordCount = countWords(str); // 调用函数计算单词个数
    cout << wordCount << endl; // 输出单词个数
    return 0;
}