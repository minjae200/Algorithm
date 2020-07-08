#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

const int MAX = 15 + 1;
const int mINF = numeric_limits<int>::min();
int N;
int cache[MAX], T[MAX], P[MAX];

int solve(int n)
{
    if(n == N+1) return 0;
    if(n > N+1) return mINF;
    int &ret = cache[n];
    if(ret != -1) return ret;
    ret = max(solve(n+1), solve(n+T[n])+P[n]);
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> T[i] >> P[i];
    }
    fill(cache, cache+MAX, -1);
    cout << solve(1) << '\n';
    return 0;
}