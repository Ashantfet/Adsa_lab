#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string exp) {
    stack<char> s;
    for (int i=0;i<exp.size();i++) {
       
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            s.push(exp[i]);
        }
        
        else if (exp[i] == ')' || exp[i] == '}' || exp[i]== ']') {
            
            if (s.empty() || (exp[i] == ')' && s.top() != '(') ||
                (exp[i] == '}' && s.top() != '{') || 
                (exp[i] == ']' && s.top() != '[')) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string exp;
    cin >> exp;
    stack<char> s;

    if (isBalanced(exp)) {
        cout << 1<< endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
