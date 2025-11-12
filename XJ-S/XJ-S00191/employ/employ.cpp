#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=998244353;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x!=0)cnt++;
    }
    int ans=1;
    for(int i=1;i<=cnt;i++){
        ans=(ans*i)%998244353;

    }
    cout<<ans%mod;
}
