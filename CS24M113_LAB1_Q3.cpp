#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> addLargeNumbers(string& num1, string& num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    int carry = 0;
    
   
    vector<int> result;

    
    int i = n1 - 1;
    int j = n2 - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        result.push_back(sum % 10);  
        carry = sum / 10;            

        i--;
        j--;
    }

    

    return result;
}

int main() {
    string num1, num2;

    
    cin >> num1;
    
    cin >> num2;

    vector<int> sum = addLargeNumbers(num1, num2);
    for(int i=sum.size()-1;i>=0;i--){
        cout  << sum[i] ;
    }
    

    return 0;
}
