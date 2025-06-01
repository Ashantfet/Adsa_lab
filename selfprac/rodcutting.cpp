#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to get the maximum revenue from cutting the rod
int rodCutting(int n, vector<int> &cost) {
    // dp[i] will store the maximum revenue for a rod of length i
    vector<int> dp(n + 1, 0);

    // Fill dp[] using the recursive relation
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], cost[j - 1] + dp[i - j]);
        }
    }

    // Return the maximum revenue for a rod of length n
    return dp[n];
}

int main() {
    // Example: cost for lengths from 1 to 8
    vector<int> cost = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = cost.size();
    
    cout  << rodCutting(n, cost) << endl;
    return 0;
}
