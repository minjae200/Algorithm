#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
int N;
int cache[MAX], card[MAX];

int solve(int n)
{
    if(n <= 0) return 0;
    int &ret = cache[n];
    if(ret != -1) return ret;
    for(int i=1; i<=n; i++) {
        ret = max(ret, solve(n-i) + card[i]);
    }
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    fill(cache, cache+MAX, -1);
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> card[i];
    }

    cout << solve(N) << '\n';
    return 0;
}