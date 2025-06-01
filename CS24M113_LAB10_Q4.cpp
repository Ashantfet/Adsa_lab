#include<iostream>
#include<vector>
using namespace std;

class disjointset{
    vector<int> par,rank;
    public:
    disjointset(int n){
        par.resize(n+1);
        rank.resize(n+1,1);
        for(int i=1;i<=n;i++){
            par[i]=i;
        }
    }
    int find(int u){
        if(u!=par[u]){
            par[u] =find(par[u]);
        }
        return par[u];
    }

    void unions(int u,int v){
        int root1=find(u);
        int root2 = find(v);
        if(root1!=root2){
            if(rank[root1] > rank[root2]){
                par[root2]=root1;
            }
            else if(rank[root1] < rank[root2]){
                par[root1]=root2;
            }
            else{
                if(root1>root2){
                    par[root2]=root1;
                }
                else{
                    par[root1]=root2;
                }
                if(par[root1]==root1){
                    rank[root1]++;
                }
                else{
                    rank[root2]++;
                }
            }
        }
    }
};
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n,m;
        cin >> n>> m;
        disjointset node(n);
            while(m--){
                int option;
                cin >> option;
                switch(option){
                    case 1:{
                        int x,y;
                        cin >> x>>y;
                        node.unions(x,y);
                        break;
                    }
                    case 2:{
                        int x;
                        cin >>x;
                        cout << node.find(x) << endl;;
                        break;
                    }
                }
            }
        }
    
    return 0;
}
