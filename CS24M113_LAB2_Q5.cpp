#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Stack {
private:
    vector<T> elements;

public:
    void push(T element) {
        elements.push_back(element);
    }
    void pop() {
        if (!isEmpty()) {
            elements.pop_back();
        } else {
            cout << "Stack underflow: Cannot pop from an empty stack." << endl;
        }
    }
    T top() const {
        if (!isEmpty()) {
            return elements.back();
        } else {
            cout << "Stack is empty: No top element." << endl;
            return T();
        }
    }
    int size() const {
        return elements.size();
    }
    bool isEmpty() const {
        return elements.empty();
    }
};

int main() {
    Stack<int> s;
    cout << "Press 1 for push. \nPress 2 for pop. \nPress 3 for top element. \nPress 4 for stack size. \nPress 5 for empty check.\nPress 0 for exit.\n";
    while(1){
    
    cout << "Enter the key: ";
    int n,p;
    cin >> n;
    switch(n){
        case 1:
               cout << "\nEnter the number to be pushed: ";
               cin >> p;
               s.push(p);
               continue;
        case 2:
               s.pop();
               cout << "\npopped!";
               continue;
        case 3:
               cout << "\nTop element: ";
               cout << s.top() << endl;
               continue;
        case 4:
               cout << "\nStack size : ";
               cout << s.size() << endl;
               continue;
        case 5:
               cout << (s.isEmpty() ? "Yes" : "No") << endl;
               continue;
        case 0: 
               return 0;
    }
    }
    return 0;
}
