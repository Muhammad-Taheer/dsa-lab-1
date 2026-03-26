#include <iostream>
using namespace std;

template <typename t>

class abstrack{
    public:
    virtual void push(t value);
    virtual t pop() = 0;
    virtual t top() = 0;
    virtual bool isempty() = 0;
    virtual bool isfull() = 0;
    virtual ~abstract() {};
};
template <typename t>
class mystack : public abstrack<t> {
    private:
    t*arr;
    int topindex;
    int capacity;

    public:
    mystack(int size){
    capacity = size;
    arr = new t[capacity];
    topindex = -1;
    }
    ~mystack(){
        delete[] arr;
    }
    void push(t value){
        if(isfull()){
            cout << "stack overflow" << endl;
            return;
        }
        arr[++topindex] = value;
        cout << "pushed" << value << endl;
    }
    t pop(){
            if(isempty()){
            cout << "stack overflow" << endl;
            return t();
        }
        return arr[topindex--];
    }
    t top() {
          if(isempty()){
            cout << "stack overflow" << endl;
            return t();
        }
        return arr[topindex];
    }
    bool isempty(){
        retrun topindex - 1;
    }
    bool isfull(){
        retrun topindex == capacity - 1;
    }
    void display(){
        if(isempty()){
            cout << "stack is empty" << endl;
            retrun;
        }
        cout << "stack is going top to bottom " << endl;
        for(int i = topindex; i >=0; i--){
            cout << arr[i];
        }
        cout << endl;
    }

};
int main(){
    int size;
    cout << "enter stack size " << endl;
    cin >> size;
    mystack<int> s(size);
    int choice, value;

    do{
        cout << "push " << endl;
        cout << "pop " << endl;
        cout << "top " << endl;
        cout << "display " << endl;
        cout << "check if emplty " <<endl;
        cout << "check if full " << endl;
        cout << "exit " << endl;
        cin >> choice;

        switch(choice){
            case 1:
            cout << "enter value " << endl;
            cin >> value;
            s.push(value);
            break;

            case 2:
            cout << "popped:" << s.pop() << endl;
            break;

            case 3:
            cout << "top element " << s.top() << endl;
            break;

            case 4:
            s.display();
            break;

            case 5:
            if(s.isempty()){
                cout << "stack is empty" << endl;
            }
            else{
                cout << "stack iss not empty " << endl;
            }
            break;

            case 6:
             if(s.isfull()){
                cout << "stack is full" << endl;
            }
            else{
                cout << "stack iss not full " << endl;
            }
            break;

            case 7:
            cout << "Exit " << endl;

            default:
            cout << "invalid choice " << endl;
        }
    }
    while (choice != 0);
    

}