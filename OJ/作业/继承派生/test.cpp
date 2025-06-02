#include <iostream>
#include <cstring>
using namespace std;

// 基类：字符串类
class String {
protected:
    char* str;    // 存储字符串的动态数组
    int length;   // 字符串长度（不含结束符）

public:
    // 构造函数，默认初始化为"1234567890"
    String(const char* s = "1234567890") {
        length = strlen(s);
        str = new char[length + 1];  // 分配空间（含结束符）
        strcpy(str, s);
    }

    // 析构函数
    virtual ~String() {
        delete[] str;
    }

    // 返回字符串内容
    const char* getString() const {
        return str;
    }

    // 返回字符串长度
    int getLength() const {
        return length;
    }
};

// 派生类：可编辑字符串类
class EditableString : public String {
public:
    // 构造函数，使用基类初始化
    EditableString() : String() {}

    // 在指定位置插入字符
    void insert(int pos, char c) {
        // 检查位置有效性（1到length+1）
        if (pos < 1 || pos > length + 1) return;
        
        char* newStr = new char[length + 2];  // 新分配空间（多一个字符）
        
        // 复制插入点前的字符
        for (int i = 0; i < pos - 1; i++) {
            newStr[i] = str[i];
        }
        
        // 插入新字符
        newStr[pos - 1] = c;
        
        // 复制插入点后的字符
        for (int i = pos - 1; i < length; i++) {
            newStr[i + 1] = str[i];
        }
        
        newStr[length + 1] = '\0';  // 添加结束符
        delete[] str;               // 释放旧内存
        str = newStr;               // 指向新内存
        length++;                   // 更新长度
    }

    // 删除指定位置的字符
    void remove(int pos) {
        // 检查位置有效性（1到length）
        if (pos < 1 || pos > length) return;
        
        char* newStr = new char[length];  // 新分配空间（少一个字符）
        
        // 复制删除点前的字符
        for (int i = 0; i < pos - 1; i++) {
            newStr[i] = str[i];
        }
        
        // 跳过删除点，复制后面的字符
        for (int i = pos; i < length; i++) {
            newStr[i - 1] = str[i];
        }
        
        newStr[length - 1] = '\0';  // 添加结束符
        delete[] str;               // 释放旧内存
        str = newStr;               // 指向新内存
        length--;                   // 更新长度
    }

    // 替换指定位置的字符
    void replace(int pos, char c) {
        // 检查位置有效性（1到length）
        if (pos < 1 || pos > length) return;
        str[pos - 1] = c;  // 直接替换字符
    }
};

int main() {
    EditableString es;
    char op;
    int pos;
    char c;

    // 循环处理指令直到遇到非编辑指令
    while (cin >> op) {
        if (op == 'i') {
            cin >> pos >> c;
            es.insert(pos, c);
            cout << es.getString() << endl;
        } else if (op == 'd') {
            cin >> pos;
            es.remove(pos);
            cout << es.getString() << endl;
        } else if (op == 'r') {
            cin >> pos >> c;
            es.replace(pos, c);
            cout << es.getString() << endl;
        } else {
            break;  // 非编辑指令退出循环
        }
    }

    return 0;
}