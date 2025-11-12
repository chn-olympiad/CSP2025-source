#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define VE vector
string s;priority_queue<LL,VE<LL>>g;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(LL i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){g.push(s[i]-'0');}
    }
    for(;!g.empty();){
        cout<<g.top();g.pop();
    }
}
