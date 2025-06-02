#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = n-1; i >0; i--)
    {
        cout << a[i] << " ";
    }
    cout << a[0]; // 输出最后一个元素，不加空格
    cout << endl;

    return 0;
}