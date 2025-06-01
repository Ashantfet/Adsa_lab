
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int mincoins(vector<int> &coin, int m, int n) {
    vector<int> dp(m + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (coin[j] <= i && dp[i - coin[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }
    
    return dp[m];
}

int main() {
    int m, n;
    cin >> m;
    cin >> n;
    
    vector<int> coin(n);
    
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    
    int ans = mincoins(coin, m, n);
    cout << ans << endl;

    return 0;
}
