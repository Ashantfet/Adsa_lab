#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countShortestPaths(int n, vector<vector<int>>& a, vector<vector<int>>& t) {
    vector<vector<int>> dp(2, vector<int>(n));
    vector<vector<int>> ways(2, vector<int>(n,0));

    int e1 = t[0][0], e2 = t[1][0];
    int x1 = t[0][n], x2 = t[1][n];

    dp[0][0] = e1 + a[0][0];
    dp[1][0] = e2 + a[1][0];
    ways[0][0] = ways[1][0] = 1;

    for (int i = 1; i < n; i++) {
         
        int route[2];
        route[0] = dp[0][i-1] + a[0][i];
        route[1] = dp[1][i-1] + t[1][i] + a[0][i];

        dp[0][i] = min(route[0], route[1]);
        if (dp[0][i] == route[0]) ways[0][i] += ways[0][i-1];
        if (dp[0][i] == route[1]) ways[0][i] += ways[1][i-1];

       
        route[0] = dp[1][i-1] + a[1][i];
        route[1] = dp[0][i-1] + t[0][i] + a[1][i];

        dp[1][i] = min(route[0], route[1]);
        if (dp[1][i] == route[0]) ways[1][i] += ways[1][i-1];
        if (dp[1][i] == route[1]) ways[1][i] += ways[0][i-1];
    }
    int exit[2];
    exit[0] = dp[0][n-1] + x1;
    exit[1] = dp[1][n-1] + x2;

    int req_time = min(exit[0], exit[1]);
    int ans = 0;

    if (req_time == exit[0]) ans += ways[0][n-1];
    if (req_time == exit[1]) ans += ways[1][n-1];

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n; 
        cin >> n;

        vector<vector<int>> a(2, vector<int>(n));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        vector<vector<int>> t(2, vector<int>(n + 1));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j <= n; j++)
                cin >> t[i][j];

        cout << countShortestPaths(n, a, t) << endl;
    }

    return 0;
}
