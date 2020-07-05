#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    int N; cin>>N;
    queue<int> q;
    for(int i=0; i<N; i++){
        string cmd; cin>>cmd;
        if(cmd == "push"){
            int data; cin>>data;
            q.push(data);
        } else if(cmd == "front"){
             if (q.empty()){
                cout<<-1<<'\n';
                continue;
            }
            cout<<q.front()<<'\n';
        } else if(cmd == "back"){
             if (q.empty()){
                cout<<-1<<'\n';
                continue;
            }
            cout<<q.back()<<'\n';
        } else if(cmd == "size"){
            cout<<q.size()<<'\n';
        } else if(cmd == "pop"){
            if (q.empty()){
                cout<<-1<<'\n';
                continue;
            }
            int data = q.front();
            q.pop();
            cout<<data<<'\n';
        } else if(cmd =="empty"){
            if(q.empty()){
                cout<<1<<'\n';
            } else{
                cout<<0<<'\n';
            }
        }
    }
    return 0;
}