#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
bool visited[MAX];
vector<int> adj[MAX];

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    printf("%d ", start);
    while(!q.empty()) {
        int data = q.front();
        q.pop();
        int size = adj[data].size();
        for(int i = 0; i < size; i++) {
            int next = adj[data][i];
            if(visited[next]) continue;
            visited[next] = true;
            printf("%d ", next);
            q.push(next);
        }
    }
}

void DFS(int start)
{
    printf("%d ", start);
    visited[start] = true;
    for(int i = 0; i < adj[start].size(); i++) {
        int next = adj[start][i];
        if(visited[next]) continue;
        DFS(next);
    }
}

int main(void)
{
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);
    for(int i = 0; i < M ; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    memset(visited, false, sizeof(visited));
    DFS(V);
    printf("\n");
    memset(visited, false, sizeof(visited));
    BFS(V);
    return 0;
}