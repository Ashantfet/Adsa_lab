#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    // cout << n << endl;
    for(int i=0;i<n;i++){
        string S,word;

        
        getline(cin >> ws, S);
        set<string> w;//unique words
        unordered_map<string, int> f;//to store the frequency of each word
        stringstream ss(S);//gives the words from sentences
        while (ss >> word) {
            w.insert(word);
            f[word]++;
        }
        for (auto& w : w) {
            cout << w << " " << f[w] << endl;
        }
        cout << endl;  
    }
    return 0;
}
