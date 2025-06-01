#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
      vector<int> a;
      int len;
    Heap()
    {
        a.push_back(-1);
        len=0;
    }
    //insertion t(n)=O(logn)
    void insertinheap(int d){
        a.push_back(d);
        len =len +1;
        int index = len;
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
    //deletion of minimum element
    int deletefromheap(){
        if(len==0){
            return -1;
        }
        if (len==1){
            int min=a[1];
            a.pop_back();
            len--;
            return min;
        }
        int min=a[1];
        a[1]=a[len];
        a.pop_back();
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
    int Sizeof() {
        return len;
    }
};
int main(){
    while (true) {
        int csum = 0;
        Heap h;
        int n;
        cin >> n;
        if(n == 0) break;

        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            h.insertinheap(a[i]);
        }

        while (h.Sizeof() > 1)
        {
            int a1= h.deletefromheap();
            int a2 = h.deletefromheap();
            int add = a1 + a2;
            csum += add;
            h.insertinheap(add);
        }
        cout << csum << endl;
    }
    return 0;
}