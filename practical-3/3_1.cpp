#include <iostream>
using namespace std;

int main()
{
    int n;
    int temp;
    cout << "Enter size of Sheet: ";
    cin >> n;
    int a[n];

    cout << "Enter sheet no.: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // ----------------------------------method 1-------------------------------------
    //  for (int i = 0; i < n; i++)
    //  {
    //      for (int j = i+1; j < n; j++)
    //      {
    //          if(a[i]>a[j]){
    //              temp = a[i];
    //              a[i] = a[j];
    //              a[j] = temp;
    //          }
    //      }
    // }

    // ----------------------------------method 2---------------------------------------
    // for (int i = 0; i < n; i++)
    // {

    //     int min = a[i];
    //     int min_i = i;
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if (a[j] < min)
    //         {
    //             min = a[j];
    //             min_i = j;
    //         }
    //     }

    //     temp = a[i];
    //     a[i] = a[min_i];
    //     a[min_i] = temp;
    // }


    // ----------------------------------method 3---------------------------------------
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j;

        for (j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j];
        }

        a[j + 1] = temp;
    }

    cout << "Shorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}