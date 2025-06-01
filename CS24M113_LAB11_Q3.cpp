#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

struct edge{
    int u,v,w;//w for weight
    bool inmst=false;
};
class disjointset{
    vector<int>par,ran;
    public:
    disjointset(int n){
        par.resize(n);
        ran.resize(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int find(int u){
        if(par[u]!=u){
            par[u]=find(par[u]);
        }
        return par[u];
    }
    bool unions(int u,int v){
        int root1=find(u);
        int root2=find(v);
        if(root1==root2) return false;
        if(ran[root1]>ran[root2]){
            par[root2]=root1;
        }
        else if(ran[root1]<ran[root2]){
            par[root1]=root2;
        }
        else{
            par[root2]=root1;
            ran[root1]++;
        }
        return true;
    }
};
int mst1(int n,vector<edge>& edgess,vector<edge*>&mst){
    disjointset dsu(n);
    sort(edgess.begin(),edgess.end(),[](edge& a,edge& b){
        return a.w<b.w;
    });
    int mstw =0;
    for(auto& edge: edgess){
        if(dsu.unions(edge.u,edge.v)){
            mstw+=edge.w;
            edge.inmst=true;
            mst.push_back(&edge);
            if(mst.size()==n-1)break;
        }
    }
    return mstw;
}
int mst2(int n,vector<edge>&edgess,vector<edge*>&mst,int mstw){
    int mst2w = INT_MAX;
    for(auto* mst:mst){
        disjointset dsu(n);
        int weights =0;
        int usededges =0;
        for(auto& edge:edgess){
            if(&edge == mst) continue;
            if(dsu.unions(edge.u,edge.v)){
                weights+=edge.w;
                usededges++;
                if(usededges ==n-1) break;
            }
        }
        /**/
        if(usededges == n-1){
            mst2w = min(mst2w,weights);

        }
    }
    return (mst2w == INT_MAX)?mstw:mst2w;
}
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n,m,i=0;
        cin >>n>>m;
        vector<edge> edgess(m);
        while(m--){
            cin >> edgess[i].u >> edgess[i].v>>edgess[i].w;
            edgess[i].inmst = false; 
            i++; 
        }
        vector<edge*>mst;
        int mstw =mst1(n,edgess,mst);
        int mst2w =mst2(n,edgess,mst,mstw);
        cout << mst2w << endl;
    }
    return 0;
}