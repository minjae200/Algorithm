#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000 + 1;
vector<int> adj[MAX];
int d[MAX], visited[MAX];
int N, M;

bool dfs(int x)
{
    for (int i=0; i<adj[x].size(); i++) {
        int y = adj[x][i];
        if(visited[y]) continue;
        visited[y] = true;
        if(d[y] == 0 || dfs(d[y])) {
            d[y] = x;
            return true;
        }
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    int TC; cin >> TC;
    while(TC--) {
        cin >> N >> M;
        for (int i=0; i<MAX; i++) {
            adj[i].clear();
        }
        fill(d, d+MAX, 0);
        for (int i=1; i<=M; i++) {
            int a, b;
            cin >> a >> b;
            for(int j=a; j<=b; j++) {
                adj[i].push_back(j);
            }
        }
        int match = 0;
        for (int i=1; i<=M; i++) {
            fill(visited, visited+MAX, false);
            if(dfs(i)) match++;
        }
        cout << match << '\n';
    }    
    return 0;
}