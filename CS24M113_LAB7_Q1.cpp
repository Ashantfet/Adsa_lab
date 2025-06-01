#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
int maxcol(vector<vector<int>>& arr, int col, int n) {
    int maxRow = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i][col] > arr[maxRow][col]) {
            maxRow = i;
        }
    }
    return maxRow;
}
int localmax(vector<vector<int>>& arr, int Col1, int Coln, int n) {
    if (Col1 == Coln) {
        int maxRow = maxcol(arr, Col1, n);
        return arr[maxRow][Col1];
    }
    int midCol = (Col1 + Coln) / 2;
    int maxRow = maxcol(arr, midCol, n);
    int maxVal = arr[maxRow][midCol];
    int lvalue = INT_MIN,rvalue=INT_MIN;
    if(midCol - 1 >= 0) lvalue=arr[maxRow][midCol - 1];
    if(midCol + 1 < n)  rvalue=arr[maxRow][midCol + 1];
    if (maxVal >= lvalue && maxVal >= rvalue) {
        return maxVal;
    }
    if (lvalue > maxVal) {
        return localmax(arr, Col1, midCol - 1, n);
    } else {
        return localmax(arr, midCol + 1, Coln, n);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
        cout  << localmax(arr,0,n-1,n) << endl;
    }
    return 0;
}
