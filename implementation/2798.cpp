#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> card;
int N, M;
int ans = 0;
vector<int> cards;
void pick(int idx, int cnt, int sum)
{
    
    if(idx > N || sum > M || cnt > 3) return;
    if(cnt==3){
        // for(int i = 0; i<cards.size(); i++){
        //     cout<<cards[i]<<" ";
        // }
        // cout<<endl;
        ans = max(ans, sum);
        return;
    }
    for(int i = idx; i<card.size(); i++){
        cards.push_back(card[i]);
        pick(i+1, cnt+1, sum+card[i]);
        cards.pop_back();
    }
}

int main(void)
{
    cin>>N>>M;
    for(int i=0; i<N; i++){
        int data; cin>>data;
        card.push_back(data);
    }
    pick(0, 0, 0);
    cout<<ans<<'\n';
    return 0;
}