#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    int N, M;
    cin >> N >> M;

    cout << N * M -1 << '\n';
    return 0;
}