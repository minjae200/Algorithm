#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
int N, M;
vector<int> edge[MAX];
bool visited[MAX];

void DFS(int cur)
{
    visited[cur] = true;
    for(int i=0; i < edge[cur].size(); i++) {
        int next = edge[cur][i];
        if (visited[next]) continue;
        DFS(next);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    fill(visited, visited + MAX, false);
    int result = 0;
    for (int i=1; i<=N; i++) {
        if(visited[i]) continue;
        DFS(i);
        result++;
    }
    cout << result << '\n';
    return 0;
}