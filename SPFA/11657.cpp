#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

const int MAX = 500 + 1;
const int INF = numeric_limits<int>::max();

long long dist[MAX], cycle[MAX];
int N, M;
bool inQ[MAX];
vector<pair<int,int>> adj[MAX];

bool SPFA(int start)
{
    queue<int> q;
    q.push(start);
    inQ[start] = true;
    dist[start] = 0;
    cycle[start]++;

    while(!q.empty()) {
        int cur = q.front();
        inQ[cur] = false;
        q.pop();

        for (int i=0; i<adj[cur].size(); i++) {
            int next = adj[cur][i].first;
            long long nDist = adj[cur][i].second;

            if (dist[next] > dist[cur] + nDist) {
                dist[next] = dist[cur] + nDist;

                if (!inQ[next]) {
                    cycle[next]++;
                    if (cycle[next] >= N) {
                        return false;
                    }
                    inQ[next] = true;
                    q.push(next);
                }
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

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int from, to, val;
        cin >> from >> to >> val;
        adj[from].push_back({to, val});
    }

    fill(dist, dist+MAX, INF);

    if (SPFA(1)) {
        for (int i=2; i<=N; i++) {
            cout << ((dist[i] == INF) ? -1 : dist[i]) << '\n';
        }
    } else cout << "-1" << '\n';
    return 0;
}