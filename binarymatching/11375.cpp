#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000 + 1;
int N, M;
vector<int> adj[MAX];
bool visited[MAX];
int occupy[MAX];

int dfs(int x)
{
    for(int i=0; i<adj[x].size(); i++) {
        int y = adj[x][i];
        if(visited[y]) continue;
        visited[y] = true;
        if(occupy[y] == 0 || dfs(occupy[y])) {
            occupy[y] = x;
            return true;
        }
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        int k; cin >> k;
        for(int j=0; j<k; j++) {
            int work; cin >> work;
            adj[i].push_back(work);
        }
    }
    int match = 0;
    for(int i=1; i<=N; i++) {
        fill(visited, visited+MAX, false);
        if(dfs(i)) match++;
    }
    cout << match << '\n';
    return 0;
}