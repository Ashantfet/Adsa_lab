#include<iostream>
using namespace std;

class Heap{
    public:
      int a[500];
      int len;
    Heap()
    {
        a[0]=-1;
        len=0;
    }
    //insertion t(n)=O(logn)
    void insertinheap(int d){
        len =len +1;
        int index = len;
        a[index] = d;
        while (index>1){
            int parent =index/2;
            if(a[parent]>a[index]){
                swap(a[parent],a[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=len;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    int deletefromheap(){
        if(len==0){
            return -1;
        }
        if (len==1){
            int min=a[1];
            len--;
            return min;
        }
        int min=a[1];
        a[1]=a[len];
        len--;

        //correction
        int i=1;
        while(true){
            int lindex=2*i;
            int rindex =2*i+1;
            int small =i;
            if(lindex <= len && a[lindex] < a[small]){
                small=lindex;
            }
            if(rindex <= len && a[rindex] < a[small]){
                small=rindex;
            }
            if(small!=i){
                swap(a[i],a[small]);
                i=small;
            }
            else{
                break;
            }
        }
        return min;
    }
    int Findmin() {
        if (len == 0) return -1;
        return a[1];
    }
    int Sizeof() {
        return len;
    }
};
int main(){
    Heap h;
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        switch(k){
            case 1:
                   int data;
                   cin >> data;
                   h.insertinheap(data);
                   break;
            case 2:
                  cout << h.Findmin() << endl;
                  break;
                   
            case 3:
                   cout << h.deletefromheap() << endl;
                   break;
            case 4:
                   cout << h.Sizeof() << endl;
                   break;
        }
    }
    return 0;
   
}
