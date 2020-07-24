#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>
using namespace std;

const int MAX = 100 + 1;
const int INF = numeric_limits<int>::max();
int people[MAX][MAX];
int N, M;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    // memset(people, 0, sizeof(people));
    fill(&people[0][0], &people[MAX-1][MAX-1], 0);
    for (int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        people[u][v] = people[v][u] = 1;
    }
    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if(i==j) continue;
                if (people[i][k] != 0 && people[k][j] != 0) {
                    if (people[i][j] == 0) people[i][j] = people[i][k] + people[k][j];
                    else people[i][j] = min(people[i][j], people[i][k] + people[k][j]);
                }
            }
        }
    }
    int ans = 1;
    int sum = INF;
    for (int i=1; i<=N; i++) {
        int temp = 0;
        for (int j=1; j<=N; j++) {
            temp += people[i][j];
        }
        if (sum > temp) {
            ans = i;
            sum = temp;
        }
    }
    cout << ans << '\n';
    return 0;
}