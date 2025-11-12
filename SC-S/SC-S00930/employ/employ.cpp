#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=505,mod=998244353;
ll fac[N],ifac[N];
inline ll qp(ll a,ll b){
    ll res=1;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)res=res*a%mod;
    return res;
}
inline ll C(ll n,ll m){return fac[n]*ifac[n-m]%mod*ifac[m]%mod;}
ll n,m,a[N];string s;
namespace t1{
    int main(){
        bool f=1;
        for(ll i=1;i<=n;i++)
            f&=(a[i]!=0&&s[i]!='0');
        cout<<(f?fac[n]:0)<<'\n';
        return 0;
    }
}
namespace t2{
    const ll N=19;
    ll p[N],a[N];
    ll f[(1<<18)+5][N];
    int main(){
        for(ll i=0;i<n;i++)p[i]=::s[i+1]-'0';
        for(ll i=0;i<n;i++)a[i]=::a[i+1];
        f[(1<<n)-1][0]=1;
        for(ll i=n;i;i--){
            for(ll s=0;s<(1<<n);s++)if(__builtin_popcount(s)==i){
                for(ll j=0;j<=n;j++)
                    for(ll k=0;k<n;k++)if((s>>k)&1){
                        ll &c=f[s-(1<<k)][j+(j>=a[k]||p[n-i]==0)];
                        c=(c+f[s][j])%mod;
                    }
            }
        }
        // for(ll s=0;s<(1<<n);s++)
        //     for(ll j=0;j<=n;j++)
        //         cerr<<s<<' '<<j<<' '<<f[s][j]<<'\n';
        ll ans=0;
        for(ll j=0;j<=n-m;j++)
            ans=(ans+f[0][j])%mod;
        cout<<ans<<"\n";
        return 0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    fac[0]=ifac[0]=1;
    for(ll i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
    ifac[N-1]=qp(fac[N-1],mod-2);
    for(ll i=N-1;i;i--)ifac[i-1]=ifac[i]*i%mod;
    cin>>n>>m>>s,s=' '+s;
    for(ll i=1;i<=n;i++)cin>>a[i];
    if(m==n)t1::main();
    else t2::main();
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}