#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void topological(int ver,int edg,vector<pair<int,int>>&givenedge){
    vector<vector<int>> adajacency(ver+1);
    vector<int>indeg(ver+1,0);
    //adjacency list and indegrees
    for(auto& edge : givenedge){
        int u=edge.first;
        int v=edge.second;
        adajacency[u].push_back(v);
        indeg[v]++;
    }
    //sorting
    for(int i=1;i<=ver;i++){
        sort(adajacency[i].begin(),adajacency[i].end());
    }
    //inserion of zero in deg in queue in incresing
    queue<int>indeg0;
    for(int i=1;i<=ver;i++){
        if(indeg[i]==0){
            indeg0.push(i);
        }
    }
    //topological   sorting
    vector<int> answer;
    while(!indeg0.empty()){
        int u=indeg0.front();
        indeg0.pop();
        answer.push_back(u);
        for(int v:adajacency[u]){
            indeg[v]--;
            if(indeg[v]==0){
                indeg0.push(v);
            }
        }
    }
    for(int i=0;i<answer.size();i++){
        if(i>0) cout <<" ";
        cout<<answer[i];
    }
    cout << endl;


}
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int ver,edg;
        cin >> ver>> edg;
        vector<pair<int,int>> givenedge(edg);
        for(int i =0;i<edg;i++){
            cin >> givenedge[i].first >> givenedge[i].second;
        }
        topological(ver,edg,givenedge);
    }
    return 0;
}