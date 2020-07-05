#include <iostream>
#include <string>
using namespace std;

string operation;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>operation;
    bool minus = false;
    string temp = "";
    int result = 0;
    for(int i=0; i<=operation.size(); i++){
        if(operation[i] == '+' || operation[i] == '-' || operation[i] == '\0'){
            if(minus){
                result -= stoi(temp);
            }else{
                result += stoi(temp);
            }
            temp = "";
            if(operation[i] == '-'){
                minus = true;
            }
            continue;
        }
        temp += operation[i];
    }
    cout<<result<<'\n';
    return 0;
}