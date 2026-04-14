#include <iostream>
using namespace std;

struct Node {
    int roll;
    string name;
    float marks;
    Node* next;
};

class StudentList {
private:
    Node* head;

public:
    StudentList() {
        head = NULL;
    }

    void insertAtEnd(int roll, string name, float marks) {
        Node* newNode = new Node();
        newNode->roll = roll;
        newNode->name = name;
        newNode->marks = marks;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtBeginning(int roll, string name, float marks) {
        Node* newNode = new Node();
        newNode->roll = roll;
        newNode->name = name;
        newNode->marks = marks;
        newNode->next = head;
        head = newNode;
    }

    void insertAfterRoll(int targetRoll, int roll, string name, float marks) {
        Node* temp = head;

        while (temp != NULL && temp->roll != targetRoll) {
            temp = temp->next;
        }

        if (temp == NULL) return;

        Node* newNode = new Node();
        newNode->roll = roll;
        newNode->name = name;
        newNode->marks = marks;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteByRoll(int roll) {
        if (head == NULL) return;

        if (head->roll == roll) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->roll != roll) {
            temp = temp->next;
        }

        if (temp->next == NULL) return;

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->roll << " " << temp->name << " " << temp->marks << endl;
            temp = temp->next;
        }
    }

    void search(int roll) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->roll == roll) {
                cout << temp->roll << " " << temp->name << " " << temp->marks << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Not Found" << endl;
    }

    void update(int roll, string name, float marks) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->roll == roll) {
                temp->name = name;
                temp->marks = marks;
                return;
            }
            temp = temp->next;
        }
    }

    void statistics() {
        if (head == NULL) return;

        float sum = 0;
        float maxMarks = head->marks;
        float minMarks = head->marks;
        int count = 0;

        Node* temp = head;

        while (temp != NULL) {
            sum += temp->marks;

            if (temp->marks > maxMarks) maxMarks = temp->marks;
            if (temp->marks < minMarks) minMarks = temp->marks;

            count++;
            temp = temp->next;
        }

        cout << "Highest: " << maxMarks << endl;
        cout << "Lowest: " << minMarks << endl;
        cout << "Average: " << sum / count << endl;
    }
};

int main() {
    StudentList list;
    int choice;

    while (choice != 0) {
        cout << "1 Insert End" << endl;
        cout << "2 Insert Beginning" << endl;
        cout << "3 Insert After Roll" << endl;
        cout << "4 Delete" << endl;
        cout << "5 Display" << endl;
        cout << "6 Search" << endl;
        cout << "7 Update" << endl;
        cout << "8 Statistics" << endl;
        cout << "9 Exit";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int r; string n; float m;
            cin >> r >> n >> m;
            list.insertAtEnd(r, n, m);
        }
        else if (choice == 2) {
            int r; string n; float m;
            cin >> r >> n >> m;
            list.insertAtBeginning(r, n, m);
        }
        else if (choice == 3) {
            int tr, r; string n; float m;
            cin >> tr >> r >> n >> m;
            list.insertAfterRoll(tr, r, n, m);
        }
        else if (choice == 4) {
            int r;
            cin >> r;
            list.deleteByRoll(r);
        }
        else if (choice == 5) {
            list.display();
        }
        else if (choice == 6) {
            int r;
            cin >> r;
            list.search(r);
        }
        else if (choice == 7) {
            int r; string n; float m;
            cin >> r >> n >> m;
            list.update(r, n, m);
        }
        else if (choice == 8) {
            list.statistics();
        }

    } while (choice != 9);

    return 0;
}