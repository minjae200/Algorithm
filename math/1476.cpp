#include <iostream>
using namespace std;

int E, S, M, result = 1;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
	cin >> E >> S >> M;
	int e, s, m;
	e = s = m = 1;
	while(1){
		if(e==E && s==S && m==M) break;
		e++; s++; m++;
		if(e > 15) e = 1;
		if(s > 28) s = 1;
		if(m > 19) m = 1;
		result++;
	}
	cout << result << '\n';
	return 0;
}