#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,c[N];
string s0[N],s1[N],s,t;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>s0[i]>>s1[i];
        int len=s0[i].size();
        for(int j=0;j<len;++j) if(s0[i][j]!=s1[i][j]) ++c[i];
    }
    for(int i=1;i<=q;++i){
        cin>>s>>t;
        int len=s.size(),d=0;
        int res=0;
        for(int j=0;j<len;++j) if(s[j]!=t[j]) ++d;
        for(int j=1;j<=n;++j){
            if(c[j]!=d) continue;
            int ll=s0[j].size();
            for(int k=0;k<=len-ll;++k){
                string a=s.substr(0,k),sub=s.substr(k,ll),b=s.substr(k+ll,len-k-ll);
                if(sub==s0[j]){
                    string ss=a+s1[j]+b;
                    if(ss==t) ++res;
                }
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}