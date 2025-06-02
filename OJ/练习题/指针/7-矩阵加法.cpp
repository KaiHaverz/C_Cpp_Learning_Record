#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    // 动态分配内存给两个矩阵
    int **matrix1 = new int*[m];
    int **matrix2 = new int*[m];
    for (int i = 0; i < m; i++) {
        matrix1[i] = new int[n];
        matrix2[i] = new int[n];
    }
    
    // 读取第一个矩阵
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> *(*(matrix1 + i) + j); // 等价于 matrix1[i][j]
        }
    }
    
    // 读取第二个矩阵
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> *(*(matrix2 + i) + j); // 等价于 matrix2[i][j]
        }
    }
    
    // 计算并输出相加后的矩阵
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 使用指针运算进行矩阵相加
            int sum = *(*(matrix1 + i) + j) + *(*(matrix2 + i) + j);
            cout << sum;
            if (j != n - 1) cout << " ";
        }
        cout << endl;
    }
    
    // 释放动态分配的内存
    for (int i = 0; i < m; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    
    return 0;
}