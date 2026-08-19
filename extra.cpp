#include <iostream>
using namespace std;

int main()
{
    int a[5] = {5,8,3,1,7};
    for (int i = 1; i < 5; i++)
    {
        for (int j = i ; j>0 ; j--)
        {
            if(a[j-1]>a[j]){
                swap(a[j-1],a[j]);
            }
            else{
                break;
            }
        } 
    }

    cout << "Shorting: ";
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    
    return 0;
}