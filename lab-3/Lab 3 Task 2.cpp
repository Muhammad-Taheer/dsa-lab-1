#include <iostream>
using namespace std;

template <typename t>
class abstractstack {
public:
    virtual void push(t value) = 0;
    virtual t pop() = 0;
    virtual t top() = 0;
    virtual bool isempty() const = 0;
    virtual bool isfull() const = 0;
    virtual ~abstractstack() {}
};
template <typename t>
class mystack : public abstractstack<t> {
private:
    t* arr;
    t* minarr;     
    int topindex;
    int mintop;
    int capacity;

public:
    mystack(int size) {
        capacity = size;
        arr = new t[capacity];
        minarr = new t[capacity];
        topindex = -1;
        mintop = -1;
    }
    ~mystack() {
        delete[] arr;
        delete[] minarr;
    }
    void push(t value) {
        if (isfull()) {
            cout << "stack overflow!" << endl;
            return;
        }

        arr[++topindex] = value;

        if (mintop == -1 || value <= minarr[mintop]) {
            minarr[++mintop] = value;
        }

        cout << "pushed: " << value << endl;
    }

    t pop() {
        if (isempty()) {
            cout << "stack underflow!" << endl;
            return t();
        }

        t popped = arr[topindex--];

        if (popped == minarr[mintop]) {
            mintop--;
        }

        return popped;
    }

    t top() {
        if (isempty()) {
            cout << "stack is empty!" << endl;
            return t();
        }
        return arr[topindex];
    }
    bool isempty() const {
        return topindex == -1;
    }

    bool isfull() const {
        return topindex == capacity - 1;
    }
    void display() const {
        if (isempty()) {
            cout << "stack is empty!" << endl;
            return;
        }

        cout << "stack (top to bottom): ";
        for (int i = topindex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    t getmin() const {
        if (mintop == -1) {
            cout << "stack is empty!" << endl;
            return t();
        }
        return minarr[mintop];
    }
};

int main() {
    int size;
    cout << "enter stack size: ";
    cin >> size;

    mystack<int> s(size);

    int choice, value;

    do {
        cout << " push element" << endl;
        cout << " pop element" << endl;
        cout << " show top element" << endl;
        cout << " check if empty" << endl;
        cout << " check if full" << endl;
        cout << " display stack" << endl;
        cout << " show minimum element" << endl;
        cout << " exit" << endl;
        cout << "enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            cout << "popped: " << s.pop() << endl;
            break;

        case 3:
            cout << "top: " << s.top() << endl;
            break;

        case 4:
            if(s.isempty()){
                cout << "stack is empty " << endl;
            }
            else{
                cout << "not empty " << endl;
            }
            break;

        case 5:
            if(s.isfull()){
            cout << "stack is full" << endl;
            }
             else{
            cout << "not full" << endl;
            }
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "minimum element: " << s.getmin() << endl;
            break;

        case 8:
            cout << "exiting..." << endl;
            break;

        default:
            cout << "invalid choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}