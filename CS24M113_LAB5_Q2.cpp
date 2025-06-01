#include <bits/stdc++.h>
using namespace std;


    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        vector<int> index(arr.size(), 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Initializition
        for(int i = 0; i < arr.size(); i++) {
            if (!arr[i].empty()) {
                pq.push({arr[i][0], i});
            }
        }
        
        vector<int> result;
        while (!pq.empty()) {
            int element = pq.top().first;
            int arrayNumber = pq.top().second;
            pq.pop();
            
            result.push_back(element);
            index[arrayNumber]++;
            
            //  adding next element in priority queue
            if (index[arrayNumber] < arr[arrayNumber].size()) {
                pq.push({arr[arrayNumber][index[arrayNumber]], arrayNumber});
            }
        }
        return result;
    }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> len(k);
        int sum = 0;
        
        for(int i = 0; i < k; i++) {
            cin >> len[i];
            sum += len[i];
        }
        
        vector<vector<int>> arr(k);
        for (int i = 0; i < k; i++) {
            arr[i].resize(len[i]);
            for(int j = 0; j < len[i]; j++) {
                cin >> arr[i][j];
            }
        }
        

        vector<int> result = mergeKArrays(arr, k);
        for(int i=0; i<sum; i++){
            cout << result[i] << " ";
            }
            cout << endl;
    }
    return 0;
}
