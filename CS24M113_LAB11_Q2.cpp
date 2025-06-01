#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

void topological(int n,vector<vector<pair<int,int>>>& adjacency,vector<bool>&isvisited,stack<int>& st){
    isvisited[n]=true;
    for(auto& i:adjacency[n]){
        int u =i.first;
        if(!isvisited[u]){
            topological(u,adjacency,isvisited,st);
        }
    }
    st.push(n);

}
vector<int>sssp_dag(int n,int s,vector<vector<pair<int,int>>>& adjacency){
    stack<int>st;
    //sorting
    vector<bool>isvisited(n,false);
    for(int i=0;i<n;i++){
        if(!isvisited[i]){
            topological(i,adjacency,isvisited,st);
        }
    }
    vector<int> distance(n,INT_MAX);
    distance[s]=0;
    //updating   
    while(!st.empty()){
        int a=st.top();
        st.pop();
        if(distance[a]!=INT_MAX){
            for(auto& i:adjacency[a]){
                int v=i.first;
                int wt=i.second;
                if(distance[a]+wt<distance[v]){
                    distance[v]=distance[a]+wt;
                }
            }
        }
    }
    return distance;

}
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n,m,s;
        cin >> n>>m>>s;
        vector<vector<pair<int,int>>>adjacency(n);
        for(int i=0;i<m;i++){
            int  u,v,w;
            cin >>u>>v>>w;
            adjacency[u].push_back({v,w});
        }
        vector<int> distance= sssp_dag(n,s,adjacency);
        for(int i=0;i<n;i++){
            if(distance[i]==INT_MAX){
                cout << "-1 ";
            }
            else
            {
                cout<< distance[i]<< " ";
            }
            
        }
        cout << endl;
    }
    return 0;
}