#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int palpart(string& word) {
    int n = word.size();

    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    vector<int> tab(n, 0);

    for (int l = 0; l < n; l++) {
        for (int b = 0; b <= l; b++) {
            if (word[b] == word[l] && (l - b <= 2 || isPalindrome[b + 1][l - 1])) {
                isPalindrome[b][l] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (isPalindrome[0][i]) {
            tab[i] = 0;
        } else {
            tab[i] = i;
            for (int j = 0; j < i; ++j) {
                if (isPalindrome[j + 1][i]) {
                    tab[i] = min(tab[i], tab[j] + 1);
                }
            }
        }
    }

    return tab[n - 1];
}

int main() {
    int t;
    cin >> t;
    while(t--){
        string word;
        cin >> word;

        cout << palpart(word) << endl;
    }  
    return 0;
}
