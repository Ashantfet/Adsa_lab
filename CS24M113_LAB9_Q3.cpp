#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int lincs(vector<int>& arr,int n) {
    
    vector<int> tab(n, 1);
    int count = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                tab[i] = max(tab[i], tab[j] + 1);
            }
        }
        count = max(count, tab[i]);
    }

    return count;
}
/*
int sumLincs(vector<int>& arr, int n) {
    vector<int> tab(n, 1);
    vector<int> sum(n, 0);

    // Initialize the sum array with the elements themselves
    for (int i = 0; i < n; i++) {
        sum[i] = arr[i];
    }

    int maxLength = 1;
    int maxSum = arr[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && tab[i] < tab[j] + 1) {
                tab[i] = tab[j] + 1;
                sum[i] = sum[j] + arr[i]; // Update sum at index i
            }
        }
        if (tab[i] > maxLength) {
            maxLength = tab[i];
            maxSum = sum[i];
        } else if (tab[i] == maxLength) {
            // Choose the larger sum if the length is the same
            maxSum = max(maxSum, sum[i]);
        }
    }

    return maxSum;
}
*/
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        cout << lincs(arr,n) << endl;
        
    }
}