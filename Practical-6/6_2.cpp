#include <iostream>
#include <string>
using namespace std;

struct Node {
    string page;
    Node* next;
};

Node* top = NULL;

void visit(string page) {
    Node* newNode = new Node();
    newNode->page = page;
    newNode->next = top;
    top = newNode;
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
