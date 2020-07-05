#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int b1, b2, b3;
	cin >> b1 >> b2 >> b3;
	int minB = min(b1, min(b2, b3));
	int k1, k2;
	cin >> k1 >> k2;
	int minK = min(k1, k2);
	cout << minB + minK - 50 << endl;
	return 0;
}