#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N;
    for(int i=2; i<=sqrt(N); i++){
        while(N%i==0){
            cout<<i<<'\n';
            N /= i;
        }
    }
    if (N != 1) cout<<N<<'\n';
    return 0;
}