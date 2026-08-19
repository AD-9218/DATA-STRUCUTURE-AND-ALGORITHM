#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> plate_no;
    string element;
    string target;
    int found = 0, i1;

    cout << "Enter 4 license plates: ";
    for (int i = 0; i < 4; i++)
    {
        cin >> element;
        plate_no.push_back(element);
    }

    cout << "Enter target plate: ";
    cin >> target;

    for (int i = 0; i < 4; i++)
    {
        if (target == plate_no[i])
        {
            i1 = i;
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        cout << "Plate found: " << plate_no[i1] << endl;
        cout << "Index: " << i1 << endl;
    }
    else
    {
        cout << "Plate not found." << endl;
    }

    return 0;
}