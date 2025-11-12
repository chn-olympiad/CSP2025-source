#include<bits/stdc++.h>
using namespace std;
namespace Main{
using lnt=long long;
int n,m;string str;int cnt;
const int mod=998244353;
void main(){
    cin>>n>>m;
    cin>>str;
    for(int i=1;i<=n;i++){
        int t;cin>>t;if(t>0)cnt++;
    }
    if(cnt<m)printf("0");
    else{
        lnt ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;ans%=mod;
        }printf("%lld",ans);
    }
}
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    Main::main();
    return 0;
}
