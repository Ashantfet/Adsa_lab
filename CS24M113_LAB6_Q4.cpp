#include <iostream>
#include <vector>
using namespace std;

// merge
int inversionCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int leftindex=left;
    int rightindex=mid+1;
    int cnt = 0;

    // Merging
    while (leftindex<=mid && rightindex<=right) {
        if (arr[leftindex] <=arr[rightindex]) {
            temp.push_back(arr[leftindex]);
            leftindex++;
        } else {
            temp.push_back(arr[rightindex]);
            cnt+=(mid-leftindex+1);
            rightindex++;
        }
    }
    //remaining left half 
    while (leftindex<=mid) {
        temp.push_back(arr[leftindex]);
         leftindex++;
    }
    //remaining right part
    while (rightindex <= right) {
        temp.push_back(arr[rightindex]);
        rightindex++;
    }
    //copying from temp to orig
    for(int i=left;i<=right;i++){
        arr[i]=temp[i-left];
    }
    return cnt;
}
//divide
int divinversion(vector<int>& arr, int left, int right) {
    int cnt = 0;
    if(left>=right) return cnt;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // left part
        cnt += divinversion(arr, left, mid);

        // right part
        cnt += divinversion(arr, mid + 1, right);

        // boundary inversion
        cnt += inversionCount(arr, left, mid, right);
    }

    return cnt;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
    }
    int tot_cnt = divinversion(arr, 0, n - 1);
    cout << tot_cnt << endl;
    }
    

    return 0;
}
