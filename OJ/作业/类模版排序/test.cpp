#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
class ArraySorter
{
public:
    static void sortArray(T arr[], int n)
    {
        sort(arr, arr + n);
    }
};

int main()
{
    // 处理整型数组
    int n1;
    cin >> n1;
    int *arr1 = new int[n1];
    for (int i = 0; i < n1; ++i)
    {
        cin >> arr1[i];
    }
    ArraySorter<int>::sortArray(arr1, n1);
    for (int i = 0; i < n1; ++i)
    {
        if (i > 0)
            cout << " ";
        cout << arr1[i];
    }
    cout << endl;
    delete[] arr1;

    // 处理字符数组
    int n2;
    cin >> n2;
    char *arr2 = new char[n2];
    for (int i = 0; i < n2; ++i)
    {
        cin >> arr2[i];
    }
    ArraySorter<char>::sortArray(arr2, n2);
    for (int i = 0; i < n2; ++i)
    {
        if (i > 0)
            cout << " ";
        cout << arr2[i];
    }
    cout << endl;
    delete[] arr2;

    // 处理字符串数组
    int n3;
    cin >> n3;
    string *arr3 = new string[n3];
    for (int i = 0; i < n3; ++i)
    {
        cin >> arr3[i];
    }
    ArraySorter<string>::sortArray(arr3, n3);
    for (int i = 0; i < n3; ++i)
    {
        if (i > 0)
            cout << " ";
        cout << arr3[i];
    }
    cout << endl;
    delete[] arr3;

    return 0;
}