#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PLL;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll N=505,K=1e6+5;

ll fpow(ll x,ll y){
    ll res=1;
    for(;y;y>>=1,x=x*x%MOD)
        if(y&1) res=res*x%MOD;
    return res;
}

ll inv[K],fact[K],invfact[K];

void init(int x){
    for(int i=2;i<=x;i++){
        inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
        fact[i]=fact[i-1]*i%MOD;
        invfact[i]=invfact[i-1]*inv[i]%MOD;
    }
}

ll A(ll n,ll m){
    if(n<0||n<m) return 0;
    return fact[n]*invfact[n-m]%MOD;
}

ll C(ll n,ll m){
    if(n<0||n<m) return 0;
    return fact[n]*invfact[m]%MOD*invfact[n-m]%MOD;
}

int n,m;
string s;
ll c[N],prec[N];
int pre0[N],far[N];

ll f[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s,s=" "+s;
    init(1e6);
    for(int i=1,x;i<=n;i++){
        cin>>x,c[x]++;
        pre0[i]=(s[i]=='0')+pre0[i-1];
    }
    for(int i=0,j=1;i<=n;i++){
        while(j<=n&&pre0[j]<i) j++;
        far[i]=j-1;
    }
    for(int i=1;i<=n;i++) prec[i]=c[i]+prec[i-1];
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=far[i];j++){
            for(int k=0;k<=far[i-1];k++){
                int ep=far[i-1]-k;
                int nowl=far[i]-far[i-1];
                for(int l=0;l<=nowl;l++){
                    f[i][j]+=f[i-1][k]*A(nowl,nowl-l)%MOD*A(n-far[i],prec[i-1]-k-nowl+l)%MOD*fpow(C(n-far[i],prec[i-1]-k),MOD-2)%MOD*A(l+ep,j-k)%MOD;
                }
            }
            f[i][j]%=MOD;
        }
    }
    ll ans=0;
    for(int i=m;i<=n;i++) ans+=f[n][i];
    cout<<ans%MOD;
}