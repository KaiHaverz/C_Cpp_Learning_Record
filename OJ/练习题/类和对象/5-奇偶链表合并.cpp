#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class List
{
public:
    Node *head;
    Node *tail;
    List() : head(nullptr), tail(nullptr) {}

    void Insert(int n)
    {
        Node *newNode = new Node(n);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void Print()
    {
        if (head == nullptr)
        {
            cout << "NULL";
            return;
        }
        Node *current = head;
        while (current)
        {
            cout << current->data;
            if (current->next)
            {
                cout << " ";
            }
            current = current->next;
        }
    }

    void Solution()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return; // 空链表或只有一个节点无需处理
        }

        Node *odd = head;        // 奇数位置节点指针
        Node *even = head->next; // 偶数位置节点指针
        Node *evenHead = even;   // 保存偶数链表的头节点

        while (even != nullptr && even->next != nullptr)
        {
            // 连接奇数节点
            odd->next = even->next;
            odd = odd->next;

            // 连接偶数节点
            even->next = odd->next;
            even = even->next;
        }

        // 将偶数链表连接到奇数链表尾部
        odd->next = evenHead;

        // 更新尾节点
        Node *current = head;
        while (current->next)
        {
            current = current->next;
        }
        tail = current;
    }
};

int main()
{
    int N;
    cin >> N;

    while (N--)
    {
        int M;
        cin >> M;

        List list;
        for (int i = 0; i < M; i++)
        {
            int num;
            cin >> num;
            list.Insert(num);
        }

        if (M > 0)
        {
            list.Solution();
        }

        list.Print();
        cout << endl;
    }

    return 0;
}