#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

bool isSubsetSum(vector<int>& arr,int n, int sum) {
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int num : arr) {
        for (int j = sum; j >= num; --j) {
            if (dp[j - num]) {
                dp[j] = true;
            }
        }
    }
    return dp[sum];
}
/*
bool subsetsum(vector<int> &arr,int n,int sum){
    vector<vector<bool>> tab(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; ++i) {
        tab[i][0] = true;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (arr[i - 1] <= j) {
                tab[i][j] = tab[i - 1][j] || tab[i - 1][j - arr[i - 1]];
            } 
            else {
                tab[i][j] = tab[i - 1][j];
            }
        }
    }
    return tab[n][sum];
}
*/
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, sum;
        cin >> n;
        cin >> sum;
        vector <int> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
       // cout << subsetsum(arr,n,sum) << endl;
        cout << isSubsetSum(arr,n,sum) << endl;
    }
}