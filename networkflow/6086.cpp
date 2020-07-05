#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

const int MAX = 52;
const int INF = numeric_limits<int>::max();
int N, result;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> adj[MAX];

void maxFlow(int start, int end)
{
    while(1)
    {
        fill(d, d+MAX, -1);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int i=0; i<adj[x].size(); i++) {
                int y = adj[x][i];
                if(c[x][y] - f[x][y] > 0 && d[y] == -1) {
                    d[y] = x;
                    q.push(y);
                    if(y==end) break;
                }
            }
        }
        if(d[end] == -1) break;
        int flow = INF;
        for(int i=end; i != start; i=d[i]) {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
        }
        for(int i=end; i!= start; i=d[i]) {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }
        result += flow;
    }
}

int CtoI(char c) {
	if (c <= 'Z') return c - 'A';
	else return c - 'a' + 26;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        char u, v;
        int capacity;
        cin >> u >> v >> capacity;
        int U = CtoI(u);
        int V = CtoI(v);
        adj[U].push_back(V);
        adj[V].push_back(U);
        c[U][V] += capacity;
        c[V][U] += capacity;
    }
    
    maxFlow('A'-'A', 'Z'-'A');
    cout << result << '\n';
    return 0;
}