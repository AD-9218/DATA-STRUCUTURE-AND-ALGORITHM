// #include <iostream>
// #include <string>
// #include <vector>
// #include<algorithm>
// using namespace std;

// int main()
// {
//     string str;
//     int sum = 0;
//     int count = 0;
//     int space = 0;
//     int last;
//     getline(cin, str);
//     vector<int> v;

//     for (int i = 0; i < str.length(); i++)
//     {
//         if (str[i] != ' ')
//         {
//             count++;
//         }
//         else
//         {
//             sum = sum + count;
//             v.push_back(count);
//             space++;
//             count = 0;
//         }
//     }

//     last = str.length() - sum - space;
//     v.push_back(last);
    
//     auto it= max_element(v.begin(),v.end());
//     cout<<"Max element is:  "<<*it<<endl;

//     return 0;
// }
#include <iostream>
#include<string>
using namespace std;

int main()

{
    string str;
    cout << "Enter a sentence: ";
    getline(cin, str);

    string longest = "";
    string word = "";

    for (int i = 0; i <= str.length(); i++)
    {
        if (str[i] != ' ' && i != str.length())
        {
            word = word + str[i];
        }
        else
        {
            if (word.length() > longest.length())
            {
                longest = word;
            }
            word = "";
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Number of characters: " << longest.length() << endl;

    return 0;
}