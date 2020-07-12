#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long dp[31][31];
int N, M;

long long solve(int n, int m)
{
	if (n == 1) return m;
	if (m == 0 || (n > m)) return 0;
	if (n == m) return 1;
	long long &ret = dp[n][m];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i <= m; i++) {
		ret += solve(n - 1, m - i);
	}
	return ret;
}

int main(void)
{
	int tc; cin >> tc;
	memset(dp, -1, sizeof(dp));
	while (tc--) {
		cin >> N >> M;
		cout << solve(N, M) << endl;
	}
	return 0;
}