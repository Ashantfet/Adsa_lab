#include <iostream>
#include <vector>
using namespace std;


bool isSymmetric( vector<vector<int>>& M) {
    int m = M.size();
    if (m == 0) return true;  
    int n = M[0].size();
    if (m != n) return false;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] != M[j][i]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int m, n;
    cin >> m;
    cin >> n;

    vector<vector<int>> M(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    if (isSymmetric(M)) {
        cout << "The matrix is symmetric." << endl;
    } else {
        cout << "The matrix is not symmetric." << endl;
    }

    return 0;
}
