#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// 打印数组前n个元素
template <class T>
void Print(T *p, int n) {
    for (int i = 0; i < n; i++) {
        cout << p[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

// 将大于阈值的元素移动到数组前部并打印
template <class T>
void GtLever(T *p, int n, T lever) {
    int count = 0; // 记录大于lever的元素数量
    for (int i = 0; i < n; i++) {
        if (p[i] > lever) {
            p[count++] = p[i]; // 将大于lever的元素移到数组前部
        }
    }
    Print(p, count); // 打印大于lever的元素
}

int main() {
    string dataType;
    int len, n;
    cin >> dataType >> len >> n;

    // 根据数据类型处理输入
    if (dataType == "int") {
        int *arr = new int[len];
        for (int i = 0; i < len; i++) {
            cin >> arr[i];
        }
        int lever;
        cin >> lever;
        GtLever(arr, n, lever);
        delete[] arr;
    } else if (dataType == "float") {
        float *arr = new float[len];
        for (int i = 0; i < len; i++) {
            cin >> arr[i];
        }
        float lever;
        cin >> lever;
        GtLever(arr, n, lever);
        delete[] arr;
    } else if (dataType == "char") {
        char *arr = new char[len];
        for (int i = 0; i < len; i++) {
            cin >> arr[i];
        }
        char lever;
        cin >> lever;
        GtLever(arr, n, lever);
        delete[] arr;
    }

    return 0;
}