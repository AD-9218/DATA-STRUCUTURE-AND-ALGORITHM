#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;

    Node(int value) {
        id = value;
        next = NULL;
    }
};

int main() {
    Node* f = NULL;
    Node* r = NULL;
    int q;

    cin >> q;

    while (q--) {
        string op;
        cin >> op;

        if (op == "add") {
            int id;
            cin >> id;

            Node* temp = new Node(id);

            if (r == NULL) {
                f = r = temp;
            } else {
                r->next = temp;
                r = temp;
            }

            cout << "Current Node: " << f->id << endl;
        }
        else if (op == "print") {
            if (f == NULL) {
                cout << "No Nodes" << endl;
            } else {
                Node* temp = f;
                f = f->next;
                delete temp;

                if (f == NULL) {
                    r = NULL;
                    cout << "No Nodes" << endl;
                } else {
                    cout << "Current Node: " << f->id << endl;
                }
            }
        }
    }

    return 0;
}
