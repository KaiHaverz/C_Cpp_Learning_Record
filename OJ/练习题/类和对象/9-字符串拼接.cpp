#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char* str;       // 字符指针（题目要求是char str; 但实际应为char*）
    int MaxLength;   // 字符串的最大长度
    
public:
    // 构造函数
    MyString(const char* s = "", int max = 100) {
        // 计算输入字符串长度
        int len = strlen(s);
        // 设置最大长度（至少为len+1）
        MaxLength = (max > len) ? max : len + 1;
        // 分配内存
        str = new char[MaxLength];
        // 复制字符串
        strcpy(str, s);
    }
    
    // 析构函数
    ~MyString() {
        delete[] str;
    }
    
    // 求字符串实际长度
    int strLen() {
        return strlen(str);
    }
    
    // 字符串连接
    void StrCat(char* s) {
        int currentLen = strlen(str);
        int addLen = strlen(s);
        // 检查空间是否足够
        if (currentLen + addLen < MaxLength) {
            strcat(str, s);
        } else {
            // 空间不足时需要重新分配
            int newLength = currentLen + addLen + 1;
            char* newStr = new char[newLength];
            strcpy(newStr, str);
            strcat(newStr, s);
            delete[] str;
            str = newStr;
            MaxLength = newLength;
        }
    }
    
    // 重载赋值运算符
    MyString& operator=(const MyString& other) {
        if (this == &other) 
            return *this;
        
        // 释放旧内存
        delete[] str;
        
        // 分配新内存
        MaxLength = other.MaxLength;
        str = new char[MaxLength];
        
        // 复制字符串
        strcpy(str, other.str);
        return *this;
    }
    
    // 获取字符串内容
    const char* getStr() {
        return str;
    }
};

int main() {
    char input1[100], input2[100];
    cin >> input1 >> input2;
    
    // 创建MyString对象
    MyString s1(input1, strlen(input1) + strlen(input2) + 1);
    
    // 输出第一个字符串的长度
    cout << s1.strLen() << endl;
    
    // 连接第二个字符串
    s1.StrCat(input2);
    
    // 输出连接后的字符串
    cout << s1.getStr() << endl;
    
    // 输出连接后的长度
    cout << s1.strLen() << endl;
    
    return 0;
}