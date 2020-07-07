#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int A,B,C;
	cin>>A>>B>>C;
	int M = max(B-A, C-B);
	cout<<M-1<<endl;
	return 0;
}