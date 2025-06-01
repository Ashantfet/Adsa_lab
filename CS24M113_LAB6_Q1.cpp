#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int crossum(vector<int>& arr, int low, int mid, int high) {
    int lsum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > lsum)
            lsum = sum;
    }
    int rsum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rsum)
            rsum = sum;
    }

    return lsum + rsum;
}
int maxsum(vector<int>& arr, int low, int high) {
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    int lsum = maxsum(arr, low, mid);
    int rsum = maxsum(arr, mid + 1, high);
    int csum = crossum(arr, low, mid, high);
    return max(lsum, max(rsum, csum));
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int result = maxsum(arr, 0, n - 1);
        cout << result << endl;
    }

    return 0;
}
