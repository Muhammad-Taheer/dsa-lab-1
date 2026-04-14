#include <iostream>
#include <string>
using namespace std;

class queue {
private:
    string* arr;
    int frontindex, rearindex, capacity;

public:
    queue(int cap) {
        capacity = cap;
        arr = new string[capacity];
        frontindex = -1;
        rearindex = -1;
    }

    ~queue() {
        delete[] arr;
    }

    void enqueue(string name) {
        if (rearindex == capacity - 1) {
            cout << "queue is full\n";
            return;
        }

        if (frontindex == -1) frontindex = 0;

        arr[++rearindex] = name;
    }

    string dequeue() {
        if (isempty()) {
            cout << "no print jobs\n";
            return "";
        }

        string value = arr[frontindex++];

        if (frontindex > rearindex) {
            frontindex = rearindex = -1;
        }

        return value;
    }

    string front() {
        if (isempty()) {
            cout << "no print jobs\n";
            return "";
        }
        return arr[frontindex];
    }

    bool isempty() {
        return frontindex == -1;
    }

    void display() {
        if (isempty()) {
            cout << "no print jobs\n";
            return;
        }

        for (int i = frontindex; i <= rearindex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int cap;
    cin >> cap;

    queue q(cap);

    int choice = -1;
    string name;

    while (choice != 0) {
        cout << "1 add job" << endl;
        cout << "2 print job" << endl;
        cout << "3 front job" << endl;
        cout << "4 display" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> name;
            q.enqueue(name);
            break;

        case 2:
            cout << q.dequeue() << endl;
            break;

        case 3:
            cout << q.front() << endl;
            break;

        case 4:
            q.display();
            break;
        }
    }

    return 0;
}