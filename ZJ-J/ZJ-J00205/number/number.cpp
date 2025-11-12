#include<bits/stdc++.h>
using namespace std;
vector<char> ans;

int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int main(){
    bool flg=0;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string now;
    cin>>now;
    for(auto it:now) if(isdigit(it)) ans.push_back(it),flg=max((int)flg,it-'0');
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    if(flg) for(auto it:ans) putchar(it);
    else cout<<0<<endl;
    return 0;
}