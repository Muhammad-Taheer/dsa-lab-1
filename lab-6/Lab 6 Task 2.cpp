#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

class linkedlist {
    node* head;

public:
    linkedlist() {
        head = nullptr;
    }

    void insertbegin(int value) {
        node* newnode = new node();
        newnode->data = value;
        newnode->next = head;
        head = newnode;
    }

    void insertend(int value) {
        node* newnode = new node();
        newnode->data = value;
        newnode->next = nullptr;

        if (head == nullptr) {
            head = newnode;
        } else {
            node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    void deletevalue(int value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next != nullptr) {
            node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    linkedlist l;

    l.insertbegin(10);
    l.insertbegin(5);
    l.insertend(20);
    l.insertend(30);

    l.display();
    cout << endl;

    l.deletevalue(20);

    l.display();

    return 0;
}