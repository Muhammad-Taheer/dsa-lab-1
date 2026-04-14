#include <iostream>
using namespace std;

class node {
public:
    string name;
    int priority;
    node* next;
};

class bookqueue {
    node* head;

public:
    bookqueue() {
        head = nullptr;
    }

    void addstudent(string n, int p) {
        node* newnode = new node();
        newnode->name = n;
        newnode->priority = p;
        newnode->next = nullptr;

        if (head == nullptr || p > head->priority) {
            newnode->next = head;
            head = newnode;
        } else {
            node* temp = head;
            while (temp->next != nullptr && temp->next->priority >= p) {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    void removestudent(string n) {
        if (head == nullptr) return;

        if (head->name == n) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* temp = head;
        while (temp->next != nullptr && temp->next->name != n) {
            temp = temp->next;
        }

        if (temp->next != nullptr) {
            node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    void updatepriority(string n, int p) {
        removestudent(n);
        addstudent(n, p);
    }

    void servefront() {
        if (head == nullptr) return;

        node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << "(" << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }

    void countstudents() {
        int count = 0;
        node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << count << endl;
    }
};

int main() {
    bookqueue book1;
    bookqueue book2;

    book1.addstudent("ali", 1);
    book1.addstudent("ahmed", 3);
    book1.addstudent("sara", 2);

    book2.addstudent("fatima", 2);
    book2.addstudent("zain", 1);
    book2.addstudent("ayesha", 3);

    cout << "book1 list: ";
    book1.display();
    book1.countstudents();

    cout << "book2 list: ";
    book2.display();
    book2.countstudents();

    book1.removestudent("ali");
    cout << "book1 after remove ali: ";
    book1.display();

    book2.updatepriority("zain", 4);
    cout << "book2 after update zain: ";
    book2.display();

    book1.servefront();
    cout << "book1 after serving front: ";
    book1.display();

    return 0;
}