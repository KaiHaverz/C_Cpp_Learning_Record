#include<iostream>

using namespace std;

//链表结构体,包含数据和一个指针
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//封装链表类
class LinkedList {
private:
    ListNode *head; //链表头指针
    ListNode* getNodeAt(int index); // 获取指定位置的节点


public:
    //构造函数和析构函数
    LinkedList() : head(nullptr) {}
    ~LinkedList(){
        clear();
    }

    // 核心操作
    void insertAtHead(int val);      // 头部插入
    void insertAtTail(int val);      // 尾部插入
    bool insertAt(int index, int val); // 指定位置插入
    bool deleteNode(int val);        // 按值删除
    bool deleteAt(int index);        // 按位置删除
    ListNode* find(int val);         // 按值查找
    int get(int index);              // 按位置获取值
    void clear();                    // 清空链表
    void print();                    // 打印链表
    int size();                      // 获取长度
};

//头部插入
void LinkedList::insertAtHead(int val) {
    ListNode *newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}
//尾部插入
void LinkedList::insertAtTail(int val) {
    ListNode *newNode = new ListNode(val);
    if (!head) {
        head = newNode;
    } else {
        ListNode *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}
//指定位置插入
bool LinkedList::insertAt(int index, int val) {
    if (index < 0) return false;
    if (index == 0) {
        insertAtHead(val);
        return true;
    }
    ListNode *newNode = new ListNode(val);
    ListNode *current = getNodeAt(index - 1);
    if (!current) return false;
    newNode->next = current->next;
    current->next = newNode;
    return true;
}
//按值删除
bool LinkedList::deleteNode(int val) {
    if (!head) return false;
    if (head->val == val) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    ListNode *current = head;
    while (current->next && current->next->val != val) {
        current = current->next;
    }
    if (!current->next) return false; // 未找到
    ListNode *temp = current->next;
    current->next = temp->next;
    delete temp;
    return true;
}
//按位置删除
bool LinkedList::deleteAt(int index) {
    if (index < 0 || !head) return false;
    if (index == 0) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    ListNode *current = getNodeAt(index - 1);
    if (!current || !current->next) return false; // 未找到
    ListNode *temp = current->next;
    current->next = temp->next;
    delete temp;
    return true;
}
//按值查找
ListNode* LinkedList::find(int val) {
    ListNode *current = head;
    while (current) {
        if (current->val == val) return current;
        current = current->next;
    }
    return nullptr; // 未找到
}
//按位置获取值
int LinkedList::get(int index) {
    ListNode *node = getNodeAt(index);
    return node ? node->val : -1; // 返回-1表示未找到
}
// 获取指定位置的节点
ListNode* LinkedList::getNodeAt(int index) {
    if (index < 0) return nullptr;
    ListNode *current = head;
    for (int i = 0; i < index && current; i++) {
        current = current->next;
    }
    return current; // 返回nullptr表示未找到
}
//清空链表
void LinkedList::clear() {
    while (head) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}
//打印链表
void LinkedList::print() {
    ListNode *current = head;
    while (current) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}
//获取链表长度
int LinkedList::size() {
    int count = 0;
    ListNode *current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}


int main(){
     LinkedList list;
    list.insertAtHead(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAt(1, 4); // 在索引1处插入4
    list.print(); // 输出: 1 -> 4 -> 2 -> 3 -> nullptr
    list.deleteNode(4); // 删除值为4的节点
    list.print(); // 输出: 1 -> 2 -> 3 -> nullptr
    cout << "Size: " << list.size() << endl; // 输出: Size: 3
    cout << "Value at index 1: " << list.get(1) << endl; // 输出: Value at index 1: 2
    list.clear(); // 清空链表
    list.print(); // 输出: nullptr
    return 0;
}