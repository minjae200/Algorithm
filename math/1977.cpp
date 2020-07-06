#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int M,N;
	cin>>M>>N;
	int sqr_M = sqrt(M);
	if(sqr_M * sqr_M < M) sqr_M = sqr_M+1;
	int sqr_N = sqrt(N);


	int sum = 0;
	for(int i = sqr_M ; i<=sqr_N; i++)
		sum += i*i;
	if(sum == 0) cout<<-1<<endl;
	else{
		cout<<sum<<endl;
		cout<<sqr_M*sqr_M<<endl;}
	return 0;
}