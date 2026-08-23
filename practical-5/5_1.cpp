#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertBeginning(string song)
{
    Node* newNode = new Node();

    newNode->song = song;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;

    cout << "Added at beginning: " << song << endl;
}

void insertEnd(string song)
{
    Node* newNode = new Node();

    newNode->song = song;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    cout << "Added at end: " << song << endl;
}

void insertAfter(string givenSong, string newSong)
{
    Node* temp = head;

    while (temp != NULL && temp->song != givenSong)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Song \"" << givenSong << "\" not found" << endl;
        return;
    }

    Node* newNode = new Node();

    newNode->song = newSong;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    cout << "Inserted " << newSong
         << " after " << givenSong << endl;
}

void deleteBeginning()
{
    if (head == NULL)
    {
        cout << "Playlist is empty" << endl;
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    cout << "Removed: " << temp->song << endl;

    delete temp;
}

int countSongs()
{
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void display()
{
    if (head == NULL)
    {
        cout << "Playlist is empty" << endl;
        return;
    }

    Node* temp = head;

    cout << "Playlist: ";

    while (temp != NULL)
    {
        cout << temp->song;

        if (temp->next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    cout << "===== MUSIC PLAYLIST =====\n\n";

    insertBeginning("Song A");
    display();

    insertEnd("Song B");
    display();

    insertEnd("Song C");
    display();

    insertAfter("Song B", "Song X");
    display();

    cout << "Number of songs: "
         << countSongs() << endl;

    deleteBeginning();
    display();

    cout << "Number of songs: "
         << countSongs() << endl;

    insertAfter("Song Z", "Song Y");
    display();

    return 0;
}