#include <iostream>
using namespace std;

const int MAX = 100 + 1;
int arr[MAX];

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    int T; cin>>T;
    cin>>arr[0];
    for(int i=1; i<T; i++){
        cin>>arr[i];
        int temp = gcd(arr[0], arr[i]);
        cout<<arr[0]/temp << "/" << arr[i]/temp<<endl;
    }
    return 0;
}