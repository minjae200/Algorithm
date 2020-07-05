#include <iostream>
#include <vector>
using namespace std;

const int MAX = 200 + 1;
int N, M;
int occupy[MAX];
bool visited[MAX];
vector<int> cow[MAX];

bool dfs(int x)
{
    for (int i=0; i<cow[x].size(); i++) {
        int y = cow[x][i];
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
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        int K; cin >> K;
        for(int j=0; j<K; j++) {
            int data; cin >> data;
            cow[i].push_back(data);
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