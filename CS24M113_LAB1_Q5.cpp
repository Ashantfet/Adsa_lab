#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int>& S1, vector<int>& S2) {
    vector<int> result;
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
    int k;
    cin >> k;

    vector<vector<int>> sets(k);
    
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        vector<int> set(n);
        for (int j = 0; j < n; j++) {
            cin >> set[j];
        }
        sort(set.begin(), set.end());
        sets[i] = set;
    }
    vector<int> result = sets[0];
    for (int i = 1; i < sets.size(); i++) {
        result = intersection(result, sets[i]);
         if (result.empty()) {
            break;
        }
    }
       
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
