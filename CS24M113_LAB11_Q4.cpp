#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
void sssp(int n,int s,vector<vector<pair<int,int>>>& adjacency,vector<int>& distance){
    distance.assign(n,INT_MAX);
    distance[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,s});
    while(!pq.empty()){
        int d=pq.top().first;
        int v=pq.top().second;
        pq.pop();
        if(d>distance[v]) continue;
        for(auto & edge :adjacency[v]){
            int ver = edge.first;
            int wt = edge.second;
            if(distance[v]+wt <distance[ver]){
                distance[ver] =distance[v]+wt;
                pq.push({distance[ver],ver});
            }
        }
    }
}
int main(){ 
    int tc;
    cin >> tc;
    while(tc--){
        int n,m;
        cin >> n>>m;
        vector<vector<pair<int,int>>>adjacency(n);
        for(int i=0;i<m;i++){ 
            int u,v,w;
            cin >> u>>v>>w;
            //undirected graph
            adjacency[u].push_back({v,w});
            adjacency[v].push_back({u,w});
        }
        int s;
        cin >> s;
        vector<int> distance(n);
        sssp(n,s,adjacency,distance);
        for(int i=0;i<n;i++){
            if(distance[i]==INT_MAX){
                cout << "-1" << " ";
            }
            else{
                cout << distance[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}