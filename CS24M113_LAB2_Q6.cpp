#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class myString {
private:
    char* str;
    int len;

public:
    myString() {
        str = new char[1];
        str[0] = '\0';
        len = 0;
    }
    ~myString() {
        delete[] str;
    }
    void init(const char* s) {
        len = strlen(s);
        delete[] str;
        str = new char[len + 1];
        strcpy(str, s); 
    }
    int length() const {
        return len;
    }
    void upper() {
        for (int i = 0; i < len; ++i) {
            str[i] = toupper(str[i]);
        }
    }
    void display() const {
        cout << str << endl;
    }
};

int main() {
    myString S;
    cout << "\nPress 1 for S.init('a') ie intialiaze.\nPress 2 for S.display(). \nPress 3 for S.upper() \nPress 4 for S.length(). \nPress 0 for exit.\n";
    while(1){
    
    cout << "Enter the key: ";
    int n;
    
    cin >> n;
    switch(n){
        case 1:
              S.init("hello");
              cout << "Initialized string: ";
              S.display();
              continue;
        case 2:
               S.display();
               continue;
        case 3:
               S.upper();
               cout << "Uppercase string: ";
               S.display();
               continue;
        case 4:
               cout << "Length of the string: " << S.length() << endl;
               continue;
        case 0: 
               return 0;
    }
    }
    return 0;
}
