#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000 + 1;
int N, M;
vector<int> adj[MAX];
int d[MAX];
bool visited[MAX];

bool DFS(int x)
{
    for(int i=0; i<adj[x].size(); i++) {
        int y = adj[x][i];
        if(visited[y]) continue;
        visited[y] = true;
        if(d[y] == 0 || DFS(d[y])) {
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

    for(int i=1; i<=N; i++) {
        int works; cin >> works;
        for(int j=0; j<works; j++) {
            int work; cin >> work;
            adj[i].push_back(work);
        }
    }

    int match = 0;
    for(int k=0; k<2; k++) {
        for(int i=1; i<=N; i++) {
            fill(visited, visited+MAX, false);
            if(DFS(i)) match++;
        }
    }
    cout << match << '\n';
    return 0;
}