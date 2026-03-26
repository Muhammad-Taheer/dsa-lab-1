#include <iostream>
#include <string>
using namespace std;

class stackstring {
private:
    string arr[100];
    int topindex;

public:
    stackstring() {
        topindex = -1;
    }

    bool isempty() {
        return topindex == -1;
    }

    bool isfull() {
        return topindex == 99;
    }

    void push(string value) {
        if (isfull()) {
            cout << "stack overflow!" << endl;
            return;
        }
        arr[++topindex] = value;
    }

    void pop() {
        if (isempty()) {
            cout << "stack underflow!" << endl;
            return;
        }
        topindex--;
    }

    string top() {
        if (isempty()) {
            return "";
        }
        return arr[topindex];
    }

    void clear() {
        topindex = -1;
    }
};

int main() {
    string text = "";
    stackstring undostack;
    stackstring redostack;

    int choice;
    char ch;

    do {
        cout << "1. type character" << endl;
        cout << "2. delete character" << endl;
        cout << "3. undo" << endl;
        cout << "4. redo" << endl;
        cout << "5. show text" << endl;
        cout << "6. exit" << endl;
        cout << "enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "enter character: ";
            cin >> ch;

            undostack.push(text);  
            text += ch;

            redostack.clear();     
            break;

        case 2:
            if (text.empty()) {
                cout << "nothing to delete!" << endl;
                break;
            }

            undostack.push(text);
            text.pop_back();

            redostack.clear();
            break;

        case 3:
            if (undostack.isempty()) {
                cout << "nothing to undo!" << endl;
                break;
            }

            redostack.push(text);
            text = undostack.top();
            undostack.pop();

            break;

        case 4:
            if (redostack.isempty()) {
                cout << "nothing to redo!" << endl;
                break;
            }

            undostack.push(text);
            text = redostack.top();
            redostack.pop();

            break;

        case 5:
            cout << "current text: " << text << endl;
            break;

        case 6:
            cout << "exiting..." << endl;
            break;

        default:
            cout << "invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}