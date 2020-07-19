#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

const int MAX = 100 + 1;
const int INF = numeric_limits<int>::max();
int n, m;
int dist[MAX][MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            dist[i][j] = INF;
        }
    }
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        dist[u][v] = min(dist[u][v], cost);
    }

    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if(i==j || dist[i][j] == INF) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}