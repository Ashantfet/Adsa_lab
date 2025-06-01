#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//padding zeros
void padding(vector<int> &num1, vector<int> &num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 < len2) {
        num1.insert(num1.begin(), len2 - len1, 0);
    } else if (len2 < len1) {
        num2.insert(num2.begin(), len1 - len2, 0);
    }
}
//splitting into two halfs
pair<vector<int>, vector<int>> split(vector<int> &num) {
    int n = num.size();
    vector<int> num1(num.begin(), num.begin() + n / 2);
    vector<int> num2(num.begin() + n / 2, num.end());
    return {num1, num2};
}
//adding two num
vector<int> add(const vector<int> &num1, const vector<int> &num2) {
    vector<int> ans(max(num1.size(), num2.size()) + 1, 0);
    int carry = 0;
    for (int i = 0; i < ans.size(); ++i) {
        int digitSum = carry;
        if (i < num1.size()) digitSum += num1[num1.size() - 1 - i];
        if (i < num2.size()) digitSum += num2[num2.size() - 1 - i];
        carry = digitSum / 10;
        ans[ans.size() - 1 - i] = digitSum % 10;
    }
    while (ans.size() > 1 && ans[0] == 0) {
        ans.erase(ans.begin());
    }
    return ans;
}
//subtracting two num
vector<int> sub(const vector<int> &num1, const vector<int> &num2) {
    vector<int> ans = num1;
    int borrow = 0;
    for (int i = 0; i < ans.size(); ++i) {
        int digitSub = ans[ans.size() - 1 - i] - borrow;
        if (i < num2.size()) digitSub -= num2[num2.size() - 1 - i];
        if (digitSub < 0) {
            digitSub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        ans[ans.size() - 1 - i] = digitSub;
    }
    while (ans.size() > 1 && ans[0] == 0) {
        ans.erase(ans.begin());
    }
    return ans;
}
//multiply by 10^n
vector<int> addzeros(const vector<int> &x, int n) {
    vector<int> ans = x;
    ans.insert(ans.end(), n, 0);
    return ans;
}
//multiplying two num
vector<int> multiply(const vector<int> &num1, const vector<int> &num2) {
    int n = max(num1.size(), num2.size());
    if (n == 1) {//base case
        int product = num1[0] * num2[0];
        if (product < 10)
            return {product};
        else
            return {product / 10, product % 10};
    }
    vector<int> x = num1, y = num2;
    padding(x, y);

    pair<vector<int>, vector<int>> x_new = split(x);
    pair<vector<int>, vector<int>> y_new = split(y);

    vector<int> x1 = x_new.first;
    vector<int> x2 = x_new.second;
    vector<int> y1 = y_new.first;
    vector<int> y2 = y_new.second;

    vector<int> p1 = multiply(x1, y1);//p1=x1*y1
    vector<int> p2 = multiply(x2, y2);//p2=x2*y2
    vector<int> p3 = multiply(add(x1, x2), add(y1, y2));//p3=(x1+x2)*(y1+y2)
    vector<int> p4 = sub(sub(p3, p1), p2);//p4 = p3-p2-p1
    vector<int> product = add(add(addzeros(p1, x2.size() + y2.size()), addzeros(p4, x2.size())),p2);//product = p1*10^n + p4*10^(n/2) + p2

    return product ;
}
int main() {
    int t;
    cin >> t;
    while(t--){
        string var1, var2;
        cin >> var1;
        cin >> var2;
        vector<int> num1 ;
        for(char c : var1){
            num1.push_back(c-'0');
        }
        vector<int> num2;
        for(char c : var2){
            num2.push_back(c-'0');
        }
        vector<int> result = multiply(num1, num2);
        for(int d : result){
            cout << d;
        }
        cout << endl;
    }
    return 0;
}