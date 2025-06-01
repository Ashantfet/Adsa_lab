#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainOrder(vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    int M[n][n];

    // Initialize the diagonal elements to 0
    for (int i = 0; i < n; i++) {
        M[i][i] = 0;
    }

    // Fill the table in a bottom-up manner
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            M[i][j] = INT_MAX;

            // Consider all possible ways to split the subproblem
            for (int k = i; k < j; k++) {
                int cost = M[i][k] + M[k+1][j] + dimensions[i] * dimensions[k+1] * dimensions[j+1];
                M[i][j] = min(M[i][j], cost);
            }
        }
    }

    return M[0][n-1];
}

int main() {
    vector<int> dimensions = {30, 35, 15, 5, 10};
    int minMultiplications = matrixChainOrder(dimensions);
    cout << "Minimum number of scalar multiplications: " << minMultiplications << endl;
    return 0;
}  