#include <iostream>
using namespace std;

int N, M, K;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> K;
    cout << min(min(N/2, M), (N+M-K)/3) << '\n';
    return 0;
}