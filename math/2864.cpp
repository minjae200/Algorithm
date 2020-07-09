#include <iostream>
#include <string>
using namespace std;

int A[7], B[7];

int main(void)
{
	string temp; cin>>temp;
	for(int i = 0; i<temp.length(); i++){
		A[i] = temp[i]-'0';
	}
	string temp2; cin>>temp2;
	for(int i = 0; i<temp2.length(); i++){
		B[i] = temp2[i]-'0';
	}
	
	int minA = 0, minB = 0;
	int maxA = 0, maxB = 0;

	for(int i = 0; i<temp.length(); i++){
		if(A[i] == 5) A[i] = 6;
		maxA = maxA *10 + A[i];
		if(A[i] == 6) A[i] = 5;
		minA = minA * 10 + A[i];
	}
	for(int i = 0; i<temp2.length(); i++){
		if(B[i] == 5) B[i] = 6;
		maxB = maxB * 10 + B[i];
		if(B[i] == 6) B[i] = 5;
		minB = minB * 10 + B[i];
	}
	

	cout<<minA+minB<<" ";
	cout<<maxA+maxB<<endl;
	return 0;
}