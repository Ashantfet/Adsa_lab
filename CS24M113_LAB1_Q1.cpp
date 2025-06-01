#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArrays(vector<int>arr1, vector<int> arr2) {
    vector<int> mergedArray;
    int i = 0, j = 0;

    
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            mergedArray.push_back(arr1[i]);
            i++;
        } else {
            mergedArray.push_back(arr2[j]);
            j++;
        }
    } 

    
    while (i < arr1.size()) {
        mergedArray.push_back(arr1[i]);
        i++;
    }

   
    while (j < arr2.size()) {
        mergedArray.push_back(arr2[j]);
        j++;
    }

    return mergedArray;
}

int main() {
    vector<int> arr1 = {14,17,21,24,27,39};
    vector<int> arr2 = {15,19,22,24,28,35};

    vector<int> mergedArray = mergeSortedArrays(arr1, arr2);   

    cout << "Merged Array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
