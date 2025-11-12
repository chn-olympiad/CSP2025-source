#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
char c[N];
int n,cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;++i){
        if(s[i]>='0'&&s[i]<='9') c[++cnt]=s[i];
    }
    sort(c+1,c+cnt+1);
    if(c[cnt]=='0') return cout<<0<<"\n",0;
    for(int i=cnt;i>=1;--i) cout<<c[i];
    cout<<"\n";
    return 0;
}