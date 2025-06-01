#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int minedit(string org_S1, string org_S2, string &up_S1, string &up_S2) {
    int m = org_S1.length();
    int n = org_S2.length();
    vector<vector<int>> editarray(m + 1, vector<int>(n + 1));

    
    for (int i = 0; i <= m; i++) {
        editarray[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        editarray[0][j] = j;
    } 
      
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (org_S1[i - 1] == org_S2[j - 1]) {
                editarray[i][j] = editarray[i - 1][j - 1];
            } else {
                editarray[i][j] = min({editarray[i - 1][j - 1] + 1, editarray[i - 1][j] + 1, editarray[i][j - 1] + 1});
            }
        }
    }

    int i = m, j = n;
    up_S1 = "";
    up_S2 = "";

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && org_S1[i - 1] == org_S2[j - 1]) {
            up_S1 += org_S1[i - 1];
            up_S2 += org_S2[j - 1];
            i--;
            j--;
        } else if (i > 0 && j > 0 && editarray[i][j] == editarray[i - 1][j - 1] + 1) {
            up_S1 += org_S1[i - 1];
            up_S2 += org_S2[j - 1];
            i--;
            j--;
        } else if (j > 0 && editarray[i][j] == editarray[i][j - 1] + 1) { 
            up_S1 += '_';
            up_S2 += org_S2[j - 1];
            j--;
        } else if (i > 0 && editarray[i][j] == editarray[i - 1][j] + 1) {
            up_S1 += org_S1[i - 1];
            up_S2 += '_';
            i--;
        }
    }
    reverse(up_S1.begin(), up_S1.end());
    reverse(up_S2.begin(), up_S2.end());

    return editarray[m][n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string org_S1;
        cin >> org_S1;
        string org_S2;
        cin >> org_S2;

        string up_S1, up_S2;
        int med = minedit(org_S1, org_S2, up_S1, up_S2);
        cout << med << endl;
        cout << up_S1 << endl;
        cout << up_S2 << endl;
    }
    return 0;
}
