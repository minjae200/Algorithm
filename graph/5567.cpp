#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 500 + 1;
int n, m;
vector<int> adj[MAX];
bool visited[MAX];

int BFS(int from)
{
    queue<int> q;
    q.push(from);
    visited[from] = true;
    int ans = -1;

    for (int i=0; i<3; i++) {
        int q_size = q.size();
        while (q_size--){
            int cur = q.front();
            q.pop();
            ans++;
            for (int j=0; j<adj[cur].size(); j++) {
                int next = adj[cur][j];
                if(visited[next]) continue;
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout <<  BFS(1) << '\n';
    return 0;
}