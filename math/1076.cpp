#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef struct _value{
	int value;
	long long gop;
}Resist;

Resist color[10];

int change(string s)
{
	if(!s.compare("black"))
		return 0;
	else if(!s.compare("brown"))
		return 1;
	else if(!s.compare("red"))
		return 2;
	else if(!s.compare("orange"))
		return 3;
	else if(!s.compare("yellow"))
		return 4;
	else if(!s.compare("green"))
		return 5;
	else if(!s.compare("blue"))
		return 6;
	else if(!s.compare("violet"))
		return 7;
	else if(!s.compare("grey"))
		return 8;
	else if(!s.compare("white"))
		return 9;
}

int main(void)
{
	string a,b,c;
	cin>>a>>b>>c;
	for(int i = 0; i<10; i++){
		color[i].value = i;
		color[i].gop = pow(10,i);
	}
	int num1 = change(a);
	int num2 = change(b);
	int num3 = change(c);

	long long result = (color[num1].value *10 + color[num2].value) * color[num3].gop;
	cout<<result<<endl;
	return 0;
}