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
     BigInteger operator*( BigInteger& b2)  {
        BigInteger result;
        for (int i = 0; i < b2.num.size(); ++i) {
             BigInteger p = mul(b2.num[i], i);
             result = result + p;
        }

        return result;
     }
     BigInteger mul(int a, int k) {
        BigInteger result;
        int carry = 0;
        int product;

        for (int i = 0; i < num.size() || carry; ++i) {
             if(i<num.size()){
               product=num[i]*a +carry;
             }
             else {
               product = carry + 0;
             }
             carry = product / 10;
             result.num.push_back(product % 10); 
        }
        for (int i = 0; i < k; ++i) {
             result.num.insert(result.num.begin(), 0);
        }

        return result;
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
BigInteger dot(BigInteger (&B1) [10],BigInteger (&B2) [10]){
    BigInteger result, ans;
    for (int i=0;i<10;i++){
        result = B1[i] * B2[i];
        ans = ans +result;
    }
    return ans;
}

int main() {
     BigInteger B1[10], B2[10], b3;
     string s1[10], s2[10];
     cout << "Enter the array of first big integer: " << endl;
     for(int i=0;i<10;i++){
        cout << "Element " << i+1 << ": " ;
        cin >> s1[i];
        B1[i].init(s1[i]);
        cout << endl;
     }
     cout << "Enter the array of second big integer: " << endl;
     for(int i=0;i<10;i++){
        cout << "Element "<< i+1 << ": ";
        cin >> s2[i];
        B2[i].init(s2[i]);
        cout << endl;
     }
     
     b3=dot(B1,B2);
     cout << "Dot Product: ";
     b3.display();
     return 0;
}

