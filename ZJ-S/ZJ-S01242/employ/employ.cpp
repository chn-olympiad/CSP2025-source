#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define forl(i,a,b) for(re ll (i)=(a);(i)<=(b);(i)++)
#define forr(i,a,b) for(re ll (i)=(a);(i)>=(b);(i)--)
#define forll(i,a,b,c) for(re ll (i)=(a);(i)<=(b);(i)+=(c))
#define forrr(i,a,b,c) for(re ll (i)=(a);(i)>=(b);(i)-=(c))
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define pii pair<ll,ll>
#define pb push_back
#define x first
#define y second
ll _t_;
ll f[(1<<18)+5][20];
ll n,m;
string s;
const ll mod=998244353;
ll a[1000010];
ll pre[1000010];
ll F(ll x){
    return pre[__builtin_popcountll(x)];
}
bool get(ll x,ll y,ll z){
    return __builtin_popcount(x)-y<a[z] && s[__builtin_popcountll(x)+1]=='1';
    // return F(x)<a[y] && s[__builtin_popcountll(x)+1]=='1';
}
ll pw(ll x){
    return 1ll<<x;
}
void add(ll&x,ll y)
{
    x+=y;
    if(x>=mod)
        x-=mod;
}
void solve()
{
    cin>>n>>m>>s;
    s=' '+s;
    forl(i,1,n)
        pre[i]=pre[i-1]+(s[i]=='0');
    forl(i,1,n)
        cin>>a[i];
    if(n==m)
    {
        forl(i,1,n)
            if(s[i]=='0' || a[i]==0)
            {
                cout<<0<<endl;
                return ;
            }
        ll ans=1;
        forl(i,1,n)
            ans=ans*i%mod;
        cout<<ans<<endl;
        return ;
    }
    f[0][0]=1;
    forl(i,0,pw(n)-2)
        forl(j,0,n)
            forl(k,1,n)
                if(!(i>>(k-1)&1))
                    add(f[i|pw(k-1)][j+get(i,j,k)],f[i][j]);
    ll ans=0;
    forl(i,m,n)
        add(ans,f[pw(n)-1][i]);
    cout<<ans<<endl;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    IOS;
    _t_=1;
    // cin>>_t_;
    while(_t_--)
        solve();
    return 0;
}