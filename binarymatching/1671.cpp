#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50 + 1;
int N;
struct Shark {
    int size, speed, intel;
    bool operator>=(Shark shark) {
        if(size >= shark.size && speed >= shark.speed && intel >= shark.intel) return true;
        else return false;
    }
    bool operator==(Shark shark) {
        if(size == shark.size && speed == shark.speed && intel == shark.intel) return true;
        else return false;
    }
};
Shark shark[MAX];
bool visited[MAX];
int occupy[MAX];
vector<int> adj[MAX];

bool dfs(int x)
{
    for(int i=0; i<adj[x].size(); i++) {
        int y = adj[x][i];
        if(visited[y]) continue;
        visited[y] = true;
        if(occupy[y] == 0 || dfs(occupy[y])){
            occupy[y] = x;
            return true;
        }
    }
    return false;
}

void setShark(void)
{
    for(int i=1; i<N; i++) {
        for(int j=i+1; j<=N; j++) {
            if(shark[i] == shark[j]) adj[i].push_back(j);
            else if(shark[i] >= shark[j]) adj[i].push_back(j);
            else if(shark[j] >= shark[i]) adj[j].push_back(i);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> shark[i].size >> shark[i].speed >> shark[i].intel;
    }
    setShark();
    int match = 0;
    for(int j=0; j<2; j++) {
        for(int i=1; i<=N; i++) {
            fill(visited, visited+MAX, false);
            if(dfs(i)) match++;
        }
    }
    cout << N - match << '\n';
    return 0;
}
