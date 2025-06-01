#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
private:
    vector<int> num;

public:
    void init(string& s) {
        for (char c : s) {
            if (isdigit(c)) {
                num.push_back(c - '0');
                }
            }
            reverse(num.begin(), num.end());
    }
    BigInteger operator+(BigInteger& b2) {
        BigInteger result;
        int carry = 0; 
        int a,b;
        int maxs = max(num.size(), b2.num.size());
        for (int i = 0; i < maxs || carry; ++i) {
            if(i<num.size()){
                a=num[i];
            }
            else{
                a=0;
            }
            if(i<b2.num.size()){
                b=b2.num[i];
            }
            else {
                b=0;
            }
            int sum = a + b + carry;
            carry = sum / 10;
            result.num.push_back(sum % 10);
            }
        return result;
    }
    void display() {
        for (auto it = num.rbegin(); it != num.rend(); ++it) {
            cout << *it;
            }
            cout << endl;
        }
};

int main() {
    BigInteger b1, b2, b3;
    string s1, s2;
    cout << "Enter first big integer: ";
    cin >> s1;
    cout << "Enter second big integer: ";
    cin >> s2;
    b1.init(s1);
    b2.init(s2);
    b3 = b1 + b2;
    cout << "Sum: ";
    b3.display();
    return 0;
}

