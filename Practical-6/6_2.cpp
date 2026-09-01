#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> stack;
    string page;
    int q;

    cin >> page;
    stack.push_back(page);

    cin >> q;

    while (q--) {
        string op;
        cin >> op;

        if (op == "push") {
            cin >> page;
            stack.push_back(page);
            cout << "Current Page: " << stack.back() << endl;
        }
        else if (op == "pop") {
            if (stack.size() == 1) {
                cout << "No History" << endl;
            } else {
                stack.pop_back();
                cout << "Current Page: " << stack.back() << endl;
            }
        }
    }

    return 0;
}