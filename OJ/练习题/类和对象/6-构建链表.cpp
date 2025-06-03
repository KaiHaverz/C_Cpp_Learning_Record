#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

// 判断是否为素数
bool isPrime(int n) {
    if (n <= 1) return false;  // 0和1不是素数
    if (n == 2) return true;    // 2是素数
    if (n % 2 == 0) return false;  // 排除偶数（除了2）
    
    // 检查奇数因子
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// 链表节点类
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// 链表类
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    
    // 插入节点（有序、不重复）
    void insert(int value) {
        // 检查是否重复
        Node* curr = head;
        while (curr) {
            if (curr->data == value) {
                return; // 重复元素，不插入
            }
            curr = curr->next;
        }
        
        // 创建新节点
        Node* newNode = new Node(value);
        
        // 处理空链表或插入头节点前的情况
        if (head == nullptr || head->data > value) {
            newNode->next = head;
            head = newNode;
            return;
        }
        
        // 寻找插入位置
        Node* prev = head;
        while (prev->next && prev->next->data < value) {
            prev = prev->next;
        }
        
        // 插入节点
        newNode->next = prev->next;
        prev->next = newNode;
    }
    
    // 打印链表
    void printList() {
        Node* curr = head;
        while (curr) {
            cout << curr->data;
            if (curr->next) {
                cout << " ";
            }
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    string input;
    getline(cin, input);  // 读取整行输入
    
    LinkedList list;
    istringstream iss(input);  // 创建字符串流
    
    int num;
    bool nonPrimeEncountered = false;
    
    // 处理每个输入的数字
    while (iss >> num) {
        if (nonPrimeEncountered) continue;  // 非素数后停止处理
        
        if (isPrime(num)) {
            list.insert(num);
        } else {
            nonPrimeEncountered = true;
        }
    }
    
    // 输出结果
    list.printList();
    
    return 0;
}