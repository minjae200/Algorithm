#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    int K; cin>>K;
    stack<int> s;
    int sum = 0;
    for(int i=0; i<K; i++){
        int data; cin>>data;
        sum += data;
        if(data==0 && !s.empty()){
            sum -= s.top();
            s.pop();
        }
        else{
            s.push(data);
        }
    }
    cout<<sum<<'\n';
    return 0;
}