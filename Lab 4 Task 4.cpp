#include <iostream>
using namespace std;

class queue {
private:
    int* arr;
    int frontindex, rearindex, capacity;

public:
    queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        frontindex = -1;
        rearindex = -1;
    }

    ~queue() {
        delete[] arr;
    }

    void enqueue(int ticket_id) {
        if (rearindex == capacity - 1) {
            cout << "queue is full\n";
            return;
        }

        if (frontindex == -1) frontindex = 0;

        arr[++rearindex] = ticket_id;
    }

    int dequeue() {
        if (isempty()) {
            cout << "no tickets\n";
            return -1;
        }

        int value = arr[frontindex++];

        if (frontindex > rearindex) {
            frontindex = rearindex = -1;
        }

        return value;
    }

    int front() {
        if (isempty()) {
            cout << "no tickets\n";
            return -1;
        }
        return arr[frontindex];
    }

    bool isempty() {
        return frontindex == -1;
    }

    void display() {
        if (isempty()) {
            cout << "no tickets\n";
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
    
    int id;
    int choice = -1;

    while (choice != 0) {
        cout << "1 add ticket" << endl;
        cout << "2 resolve ticket" << endl;
        cout << "3 next ticket" << endl;
        cout << "4 display" << endl;
        cout << "0 exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> id;
            if (id >= 1000 && id <= 9999)
                q.enqueue(id);
            else
                cout << "invalid id\n";
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