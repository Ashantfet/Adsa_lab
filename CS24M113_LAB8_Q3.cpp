#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int minijump(vector<int> &arr,int n){
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;
    vector<int> cnt(n, INT_MAX);
    cnt[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (i <= j + arr[j] && cnt[j] != INT_MAX) {
                cnt[i] = min(cnt[i], cnt[j] + 1);
                break;
            }
        }
    }
    //if(cnt[n - 1] == INT_MAX) return -1;
    return cnt[n - 1];
}/*
int minijump(vector<int> &arr,int n){
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;
    
    int count = 1;
    int next = arr[0];
    int curr = arr[0];

    for (int i = 1; i < n; i++) {
        if (i == n - 1) return count;
        next = max(next, i + arr [i]);
        if (i == curr) {
            count++;
            curr = next;
            if (curr >= n - 1) return count;
        }
    }
    return -1;
}*/

int main( ){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n;i++){
            cin >> arr[i];
        }
        int ans = minijump(arr,n);
        cout << ans << endl;
    }
    return 0;
}