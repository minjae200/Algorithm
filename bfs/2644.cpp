#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 100 + 1;
vector<int> adj[MAX];
bool visited[MAX];
int n, m, p1, p2, ans;

int bfs(void)
{
    queue<pair<int,int>> q;
    q.push({p1, 0});
    visited[p1] = true;

    while(!q.empty()) {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(cur == p2) return dist;
        for(int i=0; i<adj[cur].size(); i++) {
            int next = adj[cur][i];
            if(visited[next]) continue;
            visited[next] = true;
            q.push({next, dist+1});
        }
    }
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> n;
    cin >> p1 >> p2;
    cin >> m;

    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    cout << bfs() << '\n';
    return 0;
}
