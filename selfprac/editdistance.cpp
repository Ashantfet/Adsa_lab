#include <iostream>
#include <vector>
#include <climits>
#include<algorithm>

using namespace std;

int minEditDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    int D[m+1][n+1];

    // Initialize the first row and column
    for (int i = 0; i <= m; i++) {
        D[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        D[0][j] = j;
        
    }

    // Fill the table in a bottom-up manner
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                D[i][j] = D[i-1][j-1];
            } else {
                D[i][j] = min({D[i-1][j-1] + 1, D[i-1][j] + 1, D[i][j-1] + 1});
            }
        }
    }

    return D[m][n];
}

int main() {
    string word1 = "kitten";
    string word2 = "sitting";
    int minDistance = minEditDistance(word1, word2);
    cout << "Minimum edit distance: " << minDistance << endl;
    return 0;
}