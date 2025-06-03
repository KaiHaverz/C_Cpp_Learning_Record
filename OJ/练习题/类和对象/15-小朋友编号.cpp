#include <iostream>
#include <cstdio> // 用于快速输入输出
using namespace std;

int main() {
    int n;
    scanf("%d", &n); // 读取小朋友人数

    // 创建数组存储每个小朋友的下一位
    int next[n + 1];  // 索引从1到n

    // 读入每个小朋友的下一位信息
    for (int i = 1; i <= n; i++) {
        scanf("%d", &next[i]);
    }

    int head;
    scanf("%d", &head); // 读入队首小朋友编号

    // 直接输出队首小朋友
    printf("%d", head);
    int current = next[head]; // 下一个小朋友的编号

    // 遍历输出剩余的小朋友
    for (int i = 1; i < n; i++) {
        printf(" %d", current);
        current = next[current]; // 移动到下一位小朋友
    }

    return 0;
}