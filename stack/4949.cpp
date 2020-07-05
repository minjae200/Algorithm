#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    while(1) {
        string sentence;
        getline(cin, sentence);
        stack<char> s;
        if ( !sentence.compare(".") ) break;
        bool result = true;
        for ( int i=0; i<sentence.size(); i++) {
            if (sentence[i] == '(' || sentence[i] == '[') {
                s.push(sentence[i]);
            } else if(sentence[i] == ')' || sentence[i] == ']') {
                if (s.empty()) {
                    result = false;
                    break;
                }         
                char data = s.top();
                s.pop();
                char comp = (sentence[i] == ')') ? '(' : '[';
                if (data != comp) {
                    result = false;
                    break;
                }
            }
        }
        result = (result && s.empty()) ? true : false;
        if (result) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    return 0;
}