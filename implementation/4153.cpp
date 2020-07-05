#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	while (1)
	{
		int length[3];
		cin >> length[0] >> length[1] >> length[2];
		if (length[0] == 0 && length[1] == 0 && length[2] == 0) break;
		sort(length, length + 3);
		if (length[0] * length[0] + length[1] * length[1] == length[2] * length[2]) cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}