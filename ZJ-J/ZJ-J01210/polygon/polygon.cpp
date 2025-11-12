#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forl(i,a,b) for(re ll (i)=(a);(i)<=(b);(i)++)
#define forr(i,a,b) for(re ll (i)=(a);(i)>=(b);(i)--)
#define forll(i,a,b,c) for(re ll (i)=(a);(i)<=(b);(i)+=(c))
#define forrr(i,a,b,c) for(re ll (i)=(a);(i)>=(b);(i)-=(c))
#define pii pair<ll,ll>
#define pb push_back
ll _t_;
const ll mod=998244353;
void add(ll&x,ll y){x+=y;if(x>=mod)x-=mod;}
void del(ll&x,ll y){x-=y;if(x<0)x+=mod;}
ll n;
ll a[100010];
ll b[100010];
ll f[10010],g[10010];
ll ans;
ll fac[100010],inv[100010];
ll pw(ll x,ll y,ll mod)
{
    if(y==0)
        return 1;
    if(x==0)
        return 0;
    ll ans=1;
    while(y)
    {
        if(y&1)
            ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
void init()
{
    fac[0]=1;
    forl(i,1,1e5+5)
        fac[i]=fac[i-1]*i%mod;
    inv[100005]=pw(fac[100005],mod-2,mod);
    forr(i,100004,0)
        inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(ll n,ll m)
{
    if(n<m)
        return 0;
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
void Solve(ll x)
{
    forl(i,0,x*2+5)
        f[i]=0;
    forl(i,1,b[x])
        add(f[min(x*2+1,i*x)],C(b[x],i));
    forr(i,x-1,1)
    {
        if(b[i])
        {
            forl(j,0,x*2+5)
                g[j]=f[j];
            forl(_,1,b[i])
                forr(j,x*2+1,0)
                    add(g[min(x*2+1,j+i*_)],f[j]*C(b[i],_)%mod);
            forl(j,0,x*2+5)
                f[j]=g[j];
        }
    }
    add(ans,f[x*2+1]);
}
void solve()
{
    cin>>n;
    forl(i,1,n)
        cin>>a[i],
        b[a[i]]++;
    f[0]=1;
    forl(i,1,5000)
        if(b[i])
        {
            forl(j,0,10005)
                g[j]=f[j];
            forl(_,1,b[i])
                forr(j,10001,0)
                {
                    add(g[min(10001ll,j+i*_)],f[j]*C(b[i],_)%mod);
                    if(j+i*_>i*2)
                        add(ans,f[j]*C(b[i],_)%mod);
                }
            forl(j,0,10005)
                f[j]=g[j];
        }
    // forr(i,5000,1)
    //     if(b[i])
    //         Solve(i);
    cout<<ans<<endl;
}
int main()
{
    init();
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    IOS;
    _t_=1;
    // cin>>_t_;
    while(_t_--)
        solve();
    return 0;
}