#include <iostream>
#include <string>
using namespace std;

struct Node {
    string page;
    Node* next;
};

Node* top = NULL;

void visit(string page) {
    Node* temp = new Node();
    temp->page = page;
    temp->next = top;
    top = temp;
}

void back() {
    if (top == NULL) {
        cout << "No history left\n";
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;
}

void display() {
    if (top == NULL)
        cout << "No page\n";
    else
        cout << "Current Page: " << top->page << "\n";
}

int main() {
    visit("Google");
    display();

    visit("YouTube");
    display();

    visit("GitHub");
    display();

    back();
    display();

    back();
    display();

    back();
    display();

    return 0;
}
