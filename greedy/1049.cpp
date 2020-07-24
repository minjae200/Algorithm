#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N, M;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    // store.resize(N+1);

    int discrete = INF;
    int package = INF;
    for (int i=1; i<=M; i++) {
        int u, v;
        cin >> u >> v;
        package = min(package, u);
        discrete = min(discrete, v);
    }
    bool pless = ((discrete * 6) < package);

    if(pless) {
        cout << (N * discrete) << '\n';
    } else {
        int sum = 0;
        int cnt = (package / discrete);
        int package_cnt = N / 6;
        N = N - (6 * package_cnt);
        sum += package_cnt * package;
        if (N <= cnt) {
            sum += discrete * N;
        } else {
            sum += package;
        }
        cout << sum << '\n';
    }
    return 0;
}
