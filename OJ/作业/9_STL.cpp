#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    int N;
    cin >> N;

    while (N--)
    {
        int T;
        cin >> T;

        // 通讯列表,有顺序
        list<int> chatList;
        // 辅助集合,判断是否存在
        unordered_set<int> inList;

        for (int i = 0; i < T; i++)
        {
            int id;
            cin >> id;

            if (inList.count(id))
                chatList.remove(id);
            else
                inList.insert(id);
            chatList.push_front(id);
        }

        // 输出结果
        for (auto it = chatList.begin(); it != chatList.end(); it++)
        {
            if (it != chatList.begin())
                cout << " ";
            cout << *it;
        }
    }

    return 0;
}