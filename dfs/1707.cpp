#include <iostream>
#include <vector>
using namespace std;

const int MAX = 20000 + 1;
vector<int> adj[MAX];
int nodeColor[MAX];
int V, E;

void DFS(int v, int color)
{
    nodeColor[v] = color;

    for(int i=0; i<adj[v].size(); i++) {
        int next = adj[v][i];
        if(nodeColor[next] == 0) {
            DFS(next, 3-color);
        }
    }
}

bool isBipartiteGraph(void)
{
    for(int i=1; i<=V; i++) {
        for(int j=0; j<adj[i].size(); j++) {
            int next = adj[i][j];
            if(nodeColor[i] == nodeColor[next]) {
                return false;
            }
        }
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    int K; cin >> K;
    while(K--) {
        cin >> V >> E;
        fill(nodeColor, nodeColor+MAX, 0);
        for(int i=0; i<MAX; i++) {
            adj[i].clear();
        }
        for(int i=0; i<E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1; i<=V; i++) {
            if(nodeColor[i] == 0) {
                DFS(i, 1);
            }
        }
        if(isBipartiteGraph()) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}