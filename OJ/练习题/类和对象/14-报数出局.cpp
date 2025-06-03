#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int n;

    int lowbit(int x) {
        return x & (-x);
    }

public:
    FenwickTree(int size) {
        n = size;
        tree.assign(n + 1, 0);
        // 初始化树状数组：每个位置1
        for (int i = 1; i <= n; i++) {
            update(i, 1);
        }
    }
    
    // 更新位置index，增加delta
    void update(int index, int delta) {
        while (index <= n) {
            tree[index] += delta;
            index += lowbit(index);
        }
    }
    
    // 计算前缀和[1, index]
    int get_sum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= lowbit(index);
        }
        return sum;
    }
    
    // 查找第k个有效位置（二分查找）
    int find_kth(int k) {
        int left = 1, right = n;
        int result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int s = get_sum(mid);
            if (s >= k) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    FenwickTree fenw_tree(n);
    vector<int> result;
    int s = 1;  // 初始起始（虚拟排名）
    
    for (int i = 0; i < n; i++) {
        int all = n - i;  // 当前剩余人数
        // 计算下一个删除的位置的排名k
        int k = (s + m - 1) % all;
        if (k == 0) k = all;
        
        // 查找第k个有效位置（物理位置）
        int physical = fenw_tree.find_kth(k);
        result.push_back(physical);
        
        // 更新树状数组（删除该位置）
        fenw_tree.update(physical, -1);
        
        // 设置下一个起始排名为k
        s = k;
    }
    
    // 输出结果
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}