#include <iostream>
using namespace std;

int number[10];

void calc(int num)
{
	while (num != 0) {
		number[num % 10]++;
		num /= 10;
	}
}

int main(void)
{
	int A, B, C;
	cin >> A >> B >> C;
	long long result = A * B*C;
	calc(result);
	for (int i = 0; i < 10; i++)
		cout << number[i] << endl;
	return 0;
}