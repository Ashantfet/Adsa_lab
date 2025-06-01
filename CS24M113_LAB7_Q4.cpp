#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

double findmedian(vector<int>& Arr1, vector<int>& Arr2) {
    int m = Arr1.size();
    int n = Arr2.size();

    if (m > n) {
        return findmedian(Arr2, Arr1);
    }

    int low = 0, high = m, half_len = (m + n + 1) / 2;
    while (low <= high) {
        int i = (low + high) / 2;
        int j = half_len - i;

        int left1 = INT_MIN,left2 =INT_MIN;
        if(i != 0)  left1= Arr1[i - 1];
        if(j != 0)  left2= Arr2[j - 1];
        int right1 =  INT_MAX,right2 = INT_MAX;
        if(i != m) right1= Arr1[i];
        if(j != n) right2= Arr2[j];

        if (left1 <= right2 && left2 <= right1) {
            if ((m + n) % 2 == 0) {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } else {
                return max(left1, left2);
            }
        } else if (left1 > right2) {
            high = i - 1; 
        } else {
            low = i + 1; 
        }
    }
}

int main() {
    int m;
    cin >> m;
    vector<int> Arr1(m);
    for(int i=0;i<m;i++){
        cin >> Arr1[i];
    }
    int n;
    cin >> n;
    vector<int> Arr2(n);
    for(int i=0;i<n;i++){
        cin >> Arr2[i];
    }

    double median = findmedian(Arr1, Arr2);
    cout << median << endl;

    return 0;
}
