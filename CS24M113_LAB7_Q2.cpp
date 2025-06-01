#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int partition(vector<int>& arr, int low, int high, int pivot) {
    int pivotIndex = -1;
    for (int i = low; i <= high; i++) {
        if (arr[i] == pivot) {
            pivotIndex = i;
            break;
        }
    }
    swap(arr[pivotIndex], arr[high]);

    int i = low- 1;
    //cout <<"i value:"<< i;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


int kthsmallest(vector<int>& arr, int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }
    int n = high - low ;
    int groupSize = 5;
    int to_group = (n / groupSize)+1;

    vector<int> median;
    for (int i = 0; i < to_group; i++) {
        int groupStart = low + i * groupSize;
        int groupEnd = min(groupStart + groupSize - 1, high);
        vector<int> group(arr.begin() + groupStart, arr.begin() + groupEnd + 1);
        sort(group.begin(), group.end());
        median.push_back(group[group.size()/2]);
    }

    // so called special element (medians of median)
    int x;
    if(median.size() == 1){
        x=median[0];
    }
    else {  
        x=kthsmallest(median, 0, median.size() - 1, median.size() / 2);
    }

    // pivot index
    int q = partition(arr, low, high, x);

    int leftSize = q - low + 1;
    if (k == leftSize) {
        return arr[q];
    } else if (k < leftSize) {
        return kthsmallest(arr, low, q - 1, k);
    } else {
        return kthsmallest(arr, q + 1, high, k - leftSize );
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int ithsmallest = kthsmallest(arr, 0, arr.size() - 1, k);
    cout << ithsmallest;

    return 0;
}
