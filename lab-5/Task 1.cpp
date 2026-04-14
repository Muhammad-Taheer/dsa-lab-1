#include <iostream>
using namespace std;

const int MAX = 100;

class Stack {
private:
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char x) {
        if (top < MAX - 1) {
            arr[++top] = x;
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return '\0';
    }

    char peek() {
        if (top >= 0) {
            return arr[top];
        }
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};

string reverseString(string str) {
    Stack s;
    string result = "";

    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    while (!s.isEmpty()) {
        result += s.pop();
    }

    return result;
}

bool isBalanced(string expr) {
    Stack s;

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if (c == '(') {
            s.push(c);
        } 
        else if (c == ')') {
            if (s.isEmpty()) return false;
            s.pop();
        }
    }

    return s.isEmpty();
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            if (!s.isEmpty()) s.pop();
        }
        else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    int choice;
    string input;

    while (choice != 0) {
        cout << "1. Reverse String" << endl;
        cout << "2. Check Balanced Parentheses" << endl;
        cout << "3. Infix to Postfix" << endl;
        cout << "4. Exit " << endl;
        cout << "Enter choice: " << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter string: ";
            cin >> input;
            cout << reverseString(input) << endl;
        }
        else if (choice == 2) {
            cout << "Enter expression: ";
            cin >> input;
            if (isBalanced(input)) cout << "Balanced\n";
            else cout << "Not Balanced\n";
        }
        else if (choice == 3) {
            cout << "Enter infix: ";
            cin >> input;
            cout << infixToPostfix(input) << endl;
        }

    } while (choice != 4);

    return 0;
}