#include <iostream>
using namespace std;

class node {
public:
    string name;
    node* next;
};

class queue {
    node* head;

public:
    queue() {
        head = nullptr;
    }

    void addpatient(string n) {
        node* newnode = new node();
        newnode->name = n;
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

    void removepatient(string n) {
        if (head == nullptr) {
            return;
        }

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

    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void countpatients() {
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
    queue q;

    q.addpatient("ali");
    q.addpatient("ahmed");
    q.addpatient("sara");
    q.addpatient("fatima");

    q.display();
    q.countpatients();

    q.removepatient("ahmed");

    q.display();
    q.countpatients();

    return 0;
}