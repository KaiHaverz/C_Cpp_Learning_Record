#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Set {
private:
    int* elements;    // 存储集合元素的数组
    int capacity;     // 数组容量
    int count;        // 当前元素数量

    // 检查元素是否已存在
    bool contains(int value) {
        for (int i = 0; i < count; i++) {
            if (elements[i] == value) {
                return true;
            }
        }
        return false;
    }

    // 扩展数组容量
    void expandCapacity() {
        int newCapacity = capacity * 2;
        int* newElements = new int[newCapacity];
        memcpy(newElements, elements, count * sizeof(int));
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }

public:
    // 构造函数
    Set() : capacity(10), count(0) {
        elements = new int[capacity];
    }

    // 析构函数
    ~Set() {
        delete[] elements;
    }

    // 添加元素
    void insert(int value) {
        if (contains(value)) {
            return; // 元素已存在，不添加
        }
        
        if (count == capacity) {
            expandCapacity();
        }
        
        elements[count++] = value;
    }

    // 获取元素数量
    int size() const {
        return count;
    }

    // 重载减法运算符
    Set operator-(const Set& other) const {
        Set result;
        
        // 遍历当前集合的所有元素
        for (int i = 0; i < count; i++) {
            int value = elements[i];
            bool found = false;
            
            // 检查是否在另一个集合中
            for (int j = 0; j < other.count; j++) {
                if (value == other.elements[j]) {
                    found = true;
                    break;
                }
            }
            
            // 如果不在另一个集合中，添加到结果
            if (!found) {
                result.insert(value);
            }
        }
        
        return result;
    }

    // 输出集合内容
    void print() const {
        cout << "{";
        for (int i = 0; i < count; i++) {
            if (i > 0) {
                cout << ",";
            }
            cout << elements[i];
        }
        cout << "}";
    }
};

int main() {
    Set set1, set2;
    char input[10000];
    cin.getline(input, 10000);
    
    char* token = strtok(input, ",");
    bool readingSet1 = true;
    
    while (token != NULL) {
        if (strcmp(token, "q") == 0) {
            if (readingSet1) {
                readingSet1 = false;
            } else {
                break;
            }
        } else {
            int value = atoi(token);
            if (readingSet1) {
                set1.insert(value);
            } else {
                set2.insert(value);
            }
        }
        token = strtok(NULL, ",");
    }
    
    // 输出结果
    cout << set1.size() << endl;
    cout << set2.size() << endl;
    
    Set result = set1 - set2;
    result.print();
    cout << endl;
    
    return 0;
}