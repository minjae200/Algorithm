#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
const int MAX = 1000 + 1;
int board[MAX][MAX];
int cache[MAX][MAX];
int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cache[i][j] = board[i][j] + max(cache[i-1][j], max(cache[i][j-1], cache[i-1][j-1]));
        }
    }
    cout << cache[N][M] << '\n';
    return 0;
}