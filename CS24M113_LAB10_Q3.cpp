#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u, v, w; // w for weight
    bool operator<(edge& edge2) {
        return w < edge2.w;
    }
};

class disjointset {
public:
    vector<int> par, ran;

    disjointset(int n) {
        par.resize(n + 1);
        ran.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            par[i] = i;
        }
    }

    // Find function 
    int find(int u) {
        if (u != par[u]) {
            par[u] = find(par[u]);
        }
        return par[u];
    }

    // Union function 
    void unionSets(int u, int v) {
        int root1 = find(u);
        int root2 = find(v);
        if (root1 != root2) {
            if (ran[root1] > ran[root2]) {
                par[root2] = root1;
            } else if (ran[root1] < ran[root2]) {
                par[root1] = root2;
            } else {
                par[root2] = root1;
                ran[root1]++;
            }
        }
    }
};

// Kruskal's MST
int MSTkruskals(int n, vector<edge>& edgess, vector<edge>& mst) {
    sort(edgess.begin(), edgess.end());
    disjointset ash(n);
    int mstw = 0;
    for (auto& edge : edgess) {
        if (ash.find(edge.u) != ash.find(edge.v)) {
            mstw += edge.w;
            mst.push_back(edge);
            ash.unionSets(edge.u, edge.v);
        }
    }
    return mstw;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int m, n;
        cin >> m >> n;
        vector<edge> edgess;
        for (int i = 0; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edgess.push_back({u, v, w});
        }
        vector<edge> mst;
        int mstw = MSTkruskals(m, edgess, mst);
        cout << mstw << endl;
        for (auto& i : mst) {
            cout << i.u << " " << i.v << endl;
        }
    }
    return 0;
}
