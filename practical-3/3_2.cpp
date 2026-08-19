#include <iostream>
using namespace std;

int main()
{
    int n;
    int zero = 0, one = 0, two = 0;
    cout << "How many items in shop: ";
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            zero++;
        else if (a[i] == 1)
            one++;
        else
            two++;
    }

    int j=0;

    for (int i = 0; i < zero; i++)
    {
        a[j++]=0;
    }
    for (int i = 0; i < one; i++)
    {
        a[j++]=1;
    }
    for (int i = 0; i < two; i++)
    {
        a[j++]=2;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] <<" ";
    }
    

    return 0;
}