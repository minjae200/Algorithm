#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    stack<int> s;
    int N; cin>>N;
    for(int i=0; i<N; i++){
        string cmd; cin>>cmd;
        if(!cmd.compare("push")){
            int data; cin>>data;
            s.push(data);
        }
        else if(!cmd.compare("top")){
            if(s.empty()){
                cout<<-1<<'\n';
            }
            else cout<<s.top()<<'\n';
        }
        else if(!cmd.compare("size")){
            cout<<s.size()<<'\n';
        }
        else if(!cmd.compare("empty")){
            cout<<s.empty()<<'\n';
        }
        else if(!cmd.compare("pop")){
            if(s.empty()){
                cout<<-1<<'\n';
            }else{
                int data = s.top();
                s.pop();
                cout<<data<<'\n';
            }
        }
    }
    return 0;
}