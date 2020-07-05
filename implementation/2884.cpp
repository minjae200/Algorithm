#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int H, M;
    cin>>H>>M;
    if(H==0) H = 24;
    int cal = H*60 + M - 45;
    int hour = cal / 60;
    int minute = cal % 60;
    if (hour == 24) hour = 0;
    cout<<hour<<" "<<minute<<'\n';
    return 0;
}