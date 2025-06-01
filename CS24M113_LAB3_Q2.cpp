#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
private:
    vector<int> num;

public:
    BigInteger() {}
    void init(string& s) {
        for (char c : s) {
            if (isdigit(c)) {
                num.push_back(c - '0');
                }
            }
            reverse(num.begin(), num.end()); 
        }
    BigInteger operator*(int k){
        while(k < 0 || k > 9) {
            cout << "Enter a digit between 0 to 9" << endl;
            cout << "Reenter the digit:  " ; 
            cin >> k;
            }
            
        cout << endl;
        BigInteger result;
        int carry = 0;
        int a;
        for (int i = 0; i < num.size() || carry; ++i) {
            if(i<num.size()){
                a=num[i];
            }
            else{
                a=0;
            }
            int product = a * k + carry;
            carry = product / 10;
            result.num.push_back(product % 10);
        }
        return result;
        }
    void display(){
        for (auto it = num.rbegin(); it != num.rend(); ++it) {
            cout << *it;
            }
            cout << endl;
        }
};

int main() {
    BigInteger b1, b2;
    string s1;
    int k;
    cout << "Enter a big integer: ";
    cin >> s1;
    cout << "Enter a single digit to multiply: ";
    cin >> k;
    b1.init(s1);
    b2 = b1 * k;
    cout << "Product: ";
    b2.display();
    return 0;
}

