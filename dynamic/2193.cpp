#include <iostream>
using namespace std;

const int MAX = 90 + 1;
int N;
long long cache[MAX];

long long solve(int n)
{
    if (n==1 || n==2) return 1;
    long long &ret = cache[n];
    if(ret != -1) return ret;
    ret = solve(n-1) + solve(n-2);
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    fill(cache, cache+MAX, -1);
    cout << solve(N) << '\n';
    return 0;
}