#include <iostream>
using namespace std;

int main()
{
    bool borrow;
    int n, i1 = -1;
    bool found = false;

    cout << "How many book you Borrow: ";
    cin >> n;
    int count;
    int book_ID[n];

    cout << "Book ID: ";

    for (int i = 0; i < n; i++)
    {
        cin >> book_ID[i];
    }

    for (int j = 0; j < n; j++)
    {
        count = 0;

        for (int i = 0; i < n; i++)
        {
            if (book_ID[j] == book_ID[i])
            {
                count++;
            }
            if (count > 1)
            {
                i1 = book_ID[j];
                found = true;
                break;
                cout << "count: " << count << endl;
            }
        }
    }
    if(found){
        cout<<"More then one Borrow bOOK ID: "<<i1<<endl;
    }
}