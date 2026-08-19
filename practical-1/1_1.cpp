#include <iostream>
using namespace std;

int main()
{
    int n, h = 0;
    cout << "Enter Items:";
    cin >> n;
    cout << "Enter Time:";
    cin >> h;
    cout << "hour to rotate:" << h << endl;
    int arr[n];
    // int n1;
    cout << "Item Enter :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (h > n)
    {
        h = h % n;
    }

    for (int j = 0; j < h; j++)
    {
        int first = arr[0];

        for (int i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        arr[n - 1] = first;
    }

    cout << "Final Array is :";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }

    return 0;
}