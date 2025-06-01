#include <iostream>
#include <vector>
using namespace std;

int maxsubarraySum(vector<int> Arr, int n) {
    if (n == 0) return 0;
    int cursum = Arr[0];
    int maxsum = Arr[0];
    for (int i = 1; i < n; i++) {
        cursum = max(Arr[i], cursum + Arr[i]);
        maxsum = max(maxsum, cursum);
    }

    return maxsum;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> Arr(n);
        for (int i = 0; i < n; i++) {
            cin >> Arr[i];
        }
        int maxsum = maxsubarraySum(Arr, n);
        cout << maxsum << endl;
    }
    return 0;
}
