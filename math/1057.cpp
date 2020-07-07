#include <iostream>
using namespace std;

int main(void)
{
	int N, kim, im;
	int count = 0;
	cin>>N>>kim>>im;

	if(N < kim || N < im) count = -1;

	else
	{
		while(kim != im)
		{
			kim  = (kim+1)/2;
			im = (im+1)/2;
			count++;
		}
	}

	cout<<count<<endl;
	return 0;
}