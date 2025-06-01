#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int shortpath(vector<vector<int>>& Arr,int m,int n) {

    vector<vector<int>> tab(m, vector<int>(n, 0));

    tab[0][0] = Arr[0][0];


    for (int j = 1; j < n; j++) {
        tab[0][j] = tab[0][j - 1] + Arr[0][j];
    }
    for (int i = 1; i < m; i++) {
        tab[i][0] = tab[i - 1][0] + Arr[i][0];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            tab[i][j] = Arr[i][j] + min(tab[i - 1][j], tab[i][j - 1]);
        }
    }

    return tab[m - 1][n - 1];
}



int main( ){
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> m >> n;
        vector<vector<int>> arr(m , vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >> arr[i][j];
            }
        }

        int ans = shortpath(arr,m,n);
        cout << ans << endl;
    }
    return 0;
}