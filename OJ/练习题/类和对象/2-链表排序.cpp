#include <iostream>
#include <string>
using namespace std;

// 学生结构体
struct Student {
    int id;         // 学号
    string name;    // 姓名
};

// 节点类
class Node {
public:
    Student data;   // 学生数据
    Node* next;     // 指向下一个节点的指针
    
    Node(const Student& d) : data(d), next(nullptr) {}
};

// 链表类
class LinkedList {
private:
    Node* head;     // 头节点指针
    
public:
    LinkedList() : head(nullptr) {}
    
    ~LinkedList() {
        // 析构函数：释放所有节点
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    // 插入节点并保持升序
    void insert(const Student& data) {
        // 创建新节点
        Node* newNode = new Node(data);
        
        // 特殊情况处理：空链表或新节点应该插入到头部
        if (!head || data.id < head->data.id) {
            newNode->next = head;
            head = newNode;
            return;
        }
        
        // 查找插入位置
        Node* current = head;
        while (current->next && data.id >= current->next->data.id) {
            current = current->next;
        }
        
        // 插入节点
        newNode->next = current->next;
        current->next = newNode;
    }
    
    // 输出链表中的学生姓名
    void printNames() {
        Node* current = head;
        while (current) {
            cout << current->data.name << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;
    Student s;
    
    // 读取输入直到结束
    while (cin >> s.name >> s.id) {
        list.insert(s);
    }
    
    // 输出所有学生姓名
    list.printNames();
    
    return 0;
}