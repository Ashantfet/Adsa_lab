#include <iostream>
#include <vector>
using namespace std;

bool binarySearch( vector<int>& Arr, int key) {
    int left = 0;
    int right = Arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        
        if (Arr[mid] == key) {
            return true;
        }

        
        if (Arr[mid] < key) {
            left = mid + 1;
        }
        
        else {
            right = mid - 1;
        }
    }

   
    return false;
}

int main() {
    vector<int> Arr = {11,14,15,18,25,28,35,40,45,48,51};
    int key;



    cout << "Enter the key to search: ";
    cin >> key;

    if (binarySearch(Arr, key)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
