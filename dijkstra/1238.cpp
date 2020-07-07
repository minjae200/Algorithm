#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

const int MAX = 10000 + 1;
const int INF = numeric_limits<int>::max();
int N, M, X, result = -1;
vector<pair<int,int>> adj[MAX];
int dist[MAX];

void dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int cur = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        for(int i=0; i<adj[cur].size(); i++) {
            int next = adj[cur][i].first;
            int next_dist = cur_dist + adj[cur][i].second;
            if(next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push(make_pair(-next_dist, next));
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> X;
    for(int i=0; i<M; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back(make_pair(v, cost));
    }
    fill(dist, dist+MAX, INF);
    dijkstra(X);
    int temp[MAX];
    for(int i=1; i<=N; i++) {
        temp[i] = dist[i];
    }
    for(int i=1; i<=N; i++) {
        fill(dist, dist+MAX, INF);
        dijkstra(i);
        result = max(result, temp[i] + dist[X]);
    }
    cout << result << '\n';
    return 0;
}