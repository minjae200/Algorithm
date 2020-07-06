#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    int setting[10];
	string number; cin>>number;
	memset(setting, 0, sizeof(setting));
	int cnt = number.length();
	for(int i = 0; i<cnt; i++){
		setting[(number[i]-'0')%10]++;
	}
	int temp = setting[6];
	setting[6] = setting[6] + setting[9];
	setting[9] = setting[9] + temp;
	setting[6] = (setting[6]%2 == 0) ? setting[6]/2 : setting[6]/2+1;
	setting[9] = (setting[9]%2 == 0) ? setting[9]/2 : setting[9]/2+1;
	int maxIndex = 0;
	int max = setting[maxIndex];
	for(int i=1; i<10; i++){
		if(max < setting[i]){
			max = setting[i];
		}
	}
	cout << max << '\n';
	return 0;
}