#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	long long N, F;
	cin>>N>>F;
	long long temp = N-N%100;
	long long result = 0;
	for(long long i = temp; i<=temp+99; i++){
		if(i%F == 0){
			result = i; break;
		}
	}

	result = result - temp;
	if(result < 10) cout << 0 << result <<endl;
	else cout << result << endl;
	return 0;
}