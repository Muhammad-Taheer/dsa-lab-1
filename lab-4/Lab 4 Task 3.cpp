#include <iostream>
using namespace std;

class queue {
private:
    int* arr;
    int frontindex;
    int rearindex;
    int  capacity;

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

    void enqueue(int value) {
        if (rearindex == capacity - 1) return;

        if (frontindex == -1) frontindex = 0;

        arr[++rearindex] = value;
    }

    int dequeue() {
        if (isempty()) return -1;

        int value = arr[frontindex++];

        if (frontindex > rearindex) {
            frontindex = rearindex = -1;
        }

        return value;
    }

    int front() {
        if (isempty()) return -1;
        return arr[frontindex];
    }

    bool isempty() {
        return frontindex == -1;
    }

    int size() {
        if (isempty()) return 0;
        return rearindex - frontindex + 1;
    }

    void display() {
        for (int i = frontindex; i <= rearindex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class stack {
private:
    int* arr;
    int top, capacity;

public:
    stack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    ~stack() {
        delete[] arr;
    }

    void push(int value) {
        arr[++top] = value;
    }

    int pop() {
        return arr[top--];
    }

    bool isempty() {
        return top == -1;
    }
};

int main() {
    int n, k, x;

    cin >> n;
    queue q(n);

    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }

    cin >> k;

    if (k <= 1 || k > q.size()) {
        q.display();
        return 0;
    }

    stack s(k);

    for (int i = 0; i < k; i++) {
        s.push(q.dequeue());
    }

    while (!s.isempty()) {
        q.enqueue(s.pop());
    }

    int remaining = q.size() - k;

    for (int i = 0; i < remaining; i++) {
        q.enqueue(q.dequeue());
    }

    q.display();

    return 0;
}