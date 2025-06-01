#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;
int evaluatePostfix(string& expression) {
    stack<int> s;
    istringstream tokens(expression);
    string token;
    while (tokens >> token) {
        if (isdigit(token[0])) {
            s.push(stoi(token));
        } 
        else {
            int num1 = s.top(); s.pop(); 
            int num2 = s.top(); s.pop();

            switch (token[0]) {
                case '+':
                    s.push(num1 + num2);
                    break;
                case '-':
                    s.push(num2 - num1);
                    break;
                case '*':
                    s.push(num1 * num2);
                    break;
                case '/':
                    s.push(num2 / num1);
                    break;
            }
        }
    }
    return s.top(); 
}

int main() {
    string expression;
    getline(cin, expression); 
    int result = evaluatePostfix(expression);
    cout << result << endl;
    return 0;
}
