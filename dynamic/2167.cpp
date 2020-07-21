#include <iostream>
using namespace std;

const int MAX = 300 + 1;
int N, M, K;
int Array[MAX][MAX];
int cache[MAX][MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> Array[i][j];
            cache[i][j] = Array[i][j] + cache[i-1][j] + cache[i][j-1] - cache[i-1][j-1];
        }
    }
    cin >> K;
    while(K--) {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        int sum = cache[y2][x2]-cache[y2][x1-1]-cache[y1-1][x2]+cache[y1-1][x1-1];
        cout << sum << '\n';
    }
    return 0;
}