#include <iostream>
using namespace std;

int main() {
    int q[100];
    int f = 0;
    int r = 0;
    int op;

    cin >> op;

    while (op--) {
        string type;
        cin >> type;

        if (type == "arrive") {
            int x;
            cin >> x;

            q[r++] = x;
            cout << "Front: " << q[f] << endl;
        }
        else if (type == "attend") {
            if (f == r) {
                cout << "Queue Underflow" << endl;
            }
            else {
                f++;

                if (f == r)
                    cout << "Queue is Empty" << endl;
                else
                    cout << "Front: " << q[f] << endl;
            }
        }
    }

    return 0;
}