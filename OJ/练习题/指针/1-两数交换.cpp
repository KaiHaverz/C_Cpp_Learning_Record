#include <iostream>
using namespace std;

// 通过指针交换两个整数的值
void swapNumbers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    cin >> a >> b;
    
    // 使用指针交换值
    swapNumbers(&a, &b);
    
    // 输出交换后的结果
    cout << a << " " << b << endl;
    
    return 0;
}