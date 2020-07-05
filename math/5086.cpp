#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    int num1, num2;
    while(1){
        cin>>num1>>num2;
        if(num1 == 0 && num2 == 0){
            break;
        }
        if(num2 % num1 == 0){
            cout<<"factor"<<endl;
        }else if(num1 % num2 == 0){
            cout<<"multiple"<<endl;
        }else{
            cout<<"neither"<<endl;
        }
    }
    return 0;
}