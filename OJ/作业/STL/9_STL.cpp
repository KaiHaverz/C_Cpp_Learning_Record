#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class ChatList
{
private:
    std::vector<int> list;                // 当前的通讯列表
    std::unordered_map<int, bool> exists; // 记录好友是否已在列表中

public:
    // 处理接收到的消息序列
    void processMessages(const std::vector<int> &messages)
    {
        for (int id : messages)
        {
            if (exists.find(id) == exists.end())
            {
                // 新好友，添加到列表顶部
                list.insert(list.begin(), id);
                exists[id] = true;
            }
            else
            {
                // 已有好友，移动到列表顶部
                auto it = std::find(list.begin(), list.end(), id);
                if (it != list.end())
                {
                    list.erase(it);
                    list.insert(list.begin(), id);
                }
            }
        }
    }

    // 获取当前通讯列表
    std::vector<int> getList() const
    {
        return list;
    }

    // 清空列表，用于处理新的测试用例
    void clear()
    {
        list.clear();
        exists.clear();
    }
};

int main()
{
    int N;
    std::cin >> N;

    ChatList chatList;

    for (int i = 0; i < N; ++i)
    {
        int T;
        std::cin >> T;

        std::vector<int> messages(T);
        for (int j = 0; j < T; ++j)
        {
            std::cin >> messages[j];
        }

        chatList.clear();
        chatList.processMessages(messages);

        // 输出结果
        std::vector<int> result = chatList.getList();
        for (size_t k = 0; k < result.size(); ++k)
        {
            if (k != 0)
            {
                std::cout << " ";
            }
            std::cout << result[k];
        }
        std::cout << std::endl;
    }

    return 0;
}