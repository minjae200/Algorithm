#include <iostream>
using namespace std;

int main(void)
{
	long long S; cin>>S;
	long long N, sum;
	sum = N = 1;

	while(S-sum > N){
		N++;
		sum += N;
	}

	cout<<N<<endl;
	return 0;
}