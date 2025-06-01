
#include <iostream>
#include <vector>
using namespace std;
 int miss(vector<int> arr,int n){
    int low=0;
    int high =arr.size();
    int sum=arr[low]+arr[high];
    d=arr[1]-arr[0];

    while(low<high){
        if(sum=arr[low]+arr[high]){
            low++;
            high--;
        }
        else if(sum<arr[low]+arr[high]){
            return arr[high]+d;
        }
        else{
            return arr[low]-d;
        }
        }
        return arr[high]+d;
 }
 int main(){
    vector <int> arr;
    
    return 0;
 }