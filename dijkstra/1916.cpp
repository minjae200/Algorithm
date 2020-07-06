#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int MAX = 100000 + 1;
const int INF = numeric_limits<int>::max();
int N, M;
int d[MAX];
vector<pair<int,int>> adj[MAX];

void dijkstra(int start)
{
    d[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int dist = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        for(int i=0; i<adj[current].size(); i++) {
            int next = adj[current][i].first;
            int next_dist = adj[current][i].second + dist;
            if(next_dist < d[next]) {
                d[next] = next_dist;
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

    cin >> N >> M;
    for(int i=1; i<=M; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back(make_pair(v, cost));
    }
    int start, end;
    fill(d, d+MAX, INF);
    cin >> start >> end;
    dijkstra(start);
    cout << d[end] << '\n';
    return 0;
}