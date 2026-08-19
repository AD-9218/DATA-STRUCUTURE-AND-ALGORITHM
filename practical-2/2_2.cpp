#include <iostream>
using namespace std;

int Binary_Search(int arr[], int n, int target, int l, int h)
{
    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    int target;

    cout << "Enter the size: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted Book IDs: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target Book ID: ";
    cin >> target;

    int result = Binary_Search(arr, n, target, 0, n - 1);

    if (result != -1)
    {
        cout << "Book ID found at index: " << result << endl;
    }
    else
    {
        cout << "Book ID not found." << endl;
    }

    return 0;
}