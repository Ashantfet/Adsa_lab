#include <iostream>
#include <vector>
using namespace std;
bool matrixsearch(vector<vector<int>>& arr, int key ,int n) {
    
    if (n == 0 || arr[0].size() == 0)
        return false;
    int row = 0, col = 0;
    while (row < n && col < n) {
        if (arr[row][col] == key) {
            return true; 
        }
        else if (arr[row][col] > key) {
            row++; 
        }
        else {
            col++; 
        }
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, key;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        cin >> key;
        bool ans = matrixsearch(arr, key, n);
        cout << (ans ? "1" : "0") << endl;
    }
    return 0;
}