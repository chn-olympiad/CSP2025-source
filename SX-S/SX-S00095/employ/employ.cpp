#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans,x;
string s;
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    ans=1;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>x;
        ans=(ans*i)%mod;
    }
    cout<<ans;

    return 0;
}