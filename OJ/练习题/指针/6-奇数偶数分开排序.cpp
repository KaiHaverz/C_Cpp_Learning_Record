#include <iostream>
#include <vector>

using namespace std;

void reorderArray(int *arr, int n)
{
    vector<int> evens, odds;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evens.push_back(arr[i]);
        }
        else
        {
            odds.push_back(arr[i]);
        }
    }

    int index = 0;
    for (int num : evens)
    {
        arr[index++] = num;
    }
    for (int num : odds)
    {
        arr[index++] = num;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    reorderArray(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}