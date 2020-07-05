#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    int T; cin>>T;
    for(int i=0; i<T; i++) {
        stack<char> s;
        string str; cin>>str;
        bool result = true;
        for(int j=0; j<str.size(); j++){
            if(str[j] == '(') s.push(str[j]);
            else if(str[j] == ')'){
                if (s.empty()){
                    result = false;
                    break;
                }
                s.pop();
            }
        }
        if (!s.empty()) result = false;
        cout<< (result ? "YES" : "NO") <<'\n';
    }
    return 0;
}