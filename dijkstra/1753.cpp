#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

const int MAX = 20000 + 1;
const int INF = numeric_limits<int>::max();
int V, E, K;
vector<pair<int,int>> adj[MAX];
int d[MAX];

void dijkstra(int start)
{
    d[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()){
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if(d[current] < distance) continue;
        for(int i=0; i<adj[current].size(); i++) {
            int next = adj[current][i].first;
            int next_distance = distance + adj[current][i].second;
            if(next_distance < d[next]) {
                d[next] = next_distance;
                pq.push(make_pair(-next_distance, next));
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    cin >> V >> E >> K;
    for(int i=0; i<E; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back(make_pair(v, cost));
    }
    fill(d, d+MAX, INF);
    dijkstra(K);
    for(int i=1; i<=V; i++) {
        if (d[i] == INF) cout << "INF" << '\n';
        else cout << d[i] << '\n';
    }
    return 0;
}