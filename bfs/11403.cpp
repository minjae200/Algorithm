#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 100 + 1;
int N;
int map[MAX][MAX];
bool visited[MAX];

void DFS(int idx)
{
    for(int i=1; i<=N; i++){
        if(map[idx][i] == 1 && !visited[i]) {
            visited[i] = true;
            DFS(i);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    cin >> N;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=1; i<=N; i++) {
        memset(visited, false, sizeof(visited));
        DFS(i);
        for(int j=1; j<=N; j++) {
            if(visited[j]) map[i][j] = 1;
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}