#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100 + 1;
int N, M;
bool visited[MAX];
int d[MAX];
vector<int> adj[MAX];

bool dfs(int x)
{
    for (int i=0; i<adj[x].size(); i++) {
        int y = adj[x][i];
        if (visited[y]) continue;
        visited[y] = true;
        if (d[y] == 0 || dfs(d[y])) {
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

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int person, notebook;
        cin >> person >> notebook;
        adj[person].push_back(notebook);
    }

    int match = 0;
    memset(d, 0, sizeof(d));
    for (int i=1; i<=N; i++) {
        memset(visited, false, sizeof(visited));
        if(dfs(i)) match++;
    }
    cout << match << '\n';
    return 0;
}