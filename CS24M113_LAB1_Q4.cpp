#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int>& S1,vector<int>& S2) {
    vector<int> result;
    sort(S1.begin(), S1.end());
    sort(S2.begin(), S2.end());

    
    int i = 0, j = 0;

    while (i < S1.size() && j < S2.size()) {
        if (S1[i] < S2[j]) {
            i++;
        } else if (S1[i] > S2[j]) {
            j++;
        } else {
            result.push_back(S1[i]);
            i++;
            j++;
        }
    }

    return result;
}

int main() {
    int m, n;
    cin >> m;

    vector<int> S1(m);
    for (int i = 0; i < m; i++) {
        cin >> S1[i];
    }
    cin >> n;

    vector<int> S2(n);
    
    for (int i = 0; i < n; i++) {
        cin >> S2[i];
    }

    vector<int> result = intersection(S1, S2);
    if (result.empty()) {
        cout << -1 << endl;
    } else {
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
