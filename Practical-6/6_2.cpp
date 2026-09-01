#include <iostream>
using namespace std;

int main() {
    string stack[100];
    string page;
    int top = -1;
    int q;

    cin >> page;
    stack[++top] = page;

    cin >> q;

    while (q--) {
        string op;
        cin >> op;

        if (op == "push") {
            cin >> page;
            stack[++top] = page;
            cout << "Current Page: " << stack[top] << endl;
        }
        else if (op == "pop") {
            if (top == 0) {
                cout << "No History" << endl;
            }
            else {
                top--;
                cout << "Current Page: " << stack[top] << endl;
            }
        }
    }

    return 0;
}