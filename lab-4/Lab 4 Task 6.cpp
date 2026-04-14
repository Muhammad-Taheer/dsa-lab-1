#include <iostream>
#include <string>
using namespace std;

struct package {
    int id;
    string address;
    int starttime;
    int endtime;
};

class queue {
private:
    package* arr;
    int frontindex, rearindex, capacity;

public:
    queue(int cap) {
        capacity = cap;
        arr = new package[capacity];
        frontindex = -1;
        rearindex = -1;
    }

    ~queue() {
        delete[] arr;
    }

    void enqueue(package p) {
        if (rearindex == capacity - 1) {
            cout << "queue is full" << endl;
            return;
        }

        if (frontindex == -1) frontindex = 0;

        arr[++rearindex] = p;
    }

    void dequeue() {
        if (isempty()) {
            cout << "no packages\n";
            return;
        }

        cout << "delivered package id: " << arr[frontindex].id << endl;

        frontindex++;

        if (frontindex > rearindex) {
            frontindex = rearindex = -1;
        }
    }

    package front() {
        return arr[frontindex];
    }

    bool isempty() {
        return frontindex == -1;
    }

    void display() {
        if (isempty()) {
            cout << "no packages\n";
            return;
        }

        for (int i = frontindex; i <= rearindex; i++) {
            cout << arr[i].id << " "
                 << arr[i].address << " "
                 << arr[i].starttime << "-"
                 << arr[i].endtime << endl;
        }
    }

    void timetodeliver(int currenttime) {
        while (!isempty()) {
            package p = arr[frontindex];

            if (currenttime >= p.starttime && currenttime <= p.endtime) {
                cout << "ready to deliver package id: " << p.id << endl;
                break;
            } else {
                cout << "expired package id: " << p.id << endl;
                frontindex++;

                if (frontindex > rearindex) {
                    frontindex = rearindex = -1;
                }
            }
        }
    }
};

int main() {
    int cap;
    cin >> cap;

    queue q(cap);

    int choice = -1;

    while (choice != 0) {
        cout << "1 add package" << endl;
        cout << "2 deliver package" << endl;
        cout << "3 front package" << endl;
        cout << "4 display" << endl;
        cout << "5 check time" << endl;
        cin >> choice;

        if (choice == 1) {
            package p;
            cin >> p.id >> p.address >> p.starttime >> p.endtime;
            q.enqueue(p);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            if (!q.isempty()) {
                package p = q.front();
                cout << p.id << " " << p.address << " " << p.starttime << "-" << p.endtime << endl;
            } else {
                cout << "no packages\n";
            }
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 5) {
            int t;
            cin >> t;
            q.timetodeliver(t);
        }
    }

    return 0;
}