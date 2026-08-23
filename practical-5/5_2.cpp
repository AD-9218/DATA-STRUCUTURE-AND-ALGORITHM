#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node* next;
};

Node* head = NULL;

// Join at beginning
void insertBeginning(string name)
{
    Node* newNode = new Node();
    newNode->name = name;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Join at end
void insertEnd(string name)
{
    Node* newNode = new Node();
    newNode->name = name;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Join after a student
void insertAfter(string givenName, string newName)
{
    if (head == NULL)
    {
        cout << "Circle is empty\n";
        return;
    }

    Node* temp = head;

    do
    {
        if (temp->name == givenName)
        {
            Node* newNode = new Node();

            newNode->name = newName;
            newNode->next = temp->next;
            temp->next = newNode;

            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Student not found\n";
}

// Remove a student
void deleteStudent(string name)
{
    if (head == NULL)
    {
        cout << "Circle is empty\n";
        return;
    }

    // Only one student
    if (head->next == head)
    {
        if (head->name == name)
        {
            delete head;
            head = NULL;
        }
        else
        {
            cout << "Student not found\n";
        }

        return;
    }

    Node* current = head;
    Node* previous = NULL;

    do
    {
        if (current->name == name)
        {
            // Removing head
            if (current == head)
            {
                Node* last = head;

                while (last->next != head)
                {
                    last = last->next;
                }

                head = head->next;
                last->next = head;

                delete current;
                return;
            }

            // Removing other node
            previous->next = current->next;

            delete current;
            return;
        }

        previous = current;
        current = current->next;

    } while (current != head);

    cout << "Student not found\n";
}

// Display circle
void display()
{
    if (head == NULL)
    {
        cout << "Circle is empty\n";
        return;
    }

    Node* temp = head;

    cout << "Circle: ";

    do
    {
        cout << temp->name << " -> ";
        temp = temp->next;

    } while (temp != head);

    cout << "(back to " << head->name << ")\n";
}

int main()
{
    cout << "===== CIRCULAR SINGLY LINKED LIST =====\n\n";

    insertEnd("A");
    display();

    insertEnd("B");
    display();

    insertEnd("C");
    display();

    insertAfter("B", "X");
    display();

    deleteStudent("B");
    display();

    deleteStudent("A");
    display();

    return 0;
}