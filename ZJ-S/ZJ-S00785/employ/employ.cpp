#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e18;
#define Max(x,y) x = max(x,y)
#define Min(x,y) x = min(x,y)
#define fr(i,l,r) for (i=(l); i<=(r); i++)
#define rfr(i,l,r) for (i=(l); i>=(r); i--)
template<typename T>inline void read(T &n){
    T w = 1; n = 0; char ch = getchar();
    while (!isdigit(ch) && ch!=EOF){
        if (ch=='-') w = -1;
        ch = getchar();
    }
    while (isdigit(ch) && ch!=EOF){
        n = n*10 + ch-'0';
        ch = getchar();
    }
    n *= w;
}
const ll N = 505, mod = 998244353;
void pls(ll &x,ll y){
    x += y;
    if (x>=mod) x -= mod;
}
ll pw(ll x,ll y){
    ll ans = 1;
    while (y){
        if (y&1) ans = ans*x %mod;
        x = x*x %mod;
        y >>= 1;
    }
    return ans;
}
struct Comb{
    ll jc[N], fjc[N];
    void init(ll n){
        ll i;
        jc[0] = 1;
        fr(i,1,n) jc[i] = jc[i-1]*i %mod;
        fjc[n] = pw(jc[n],mod-2);
        rfr(i,n-1,0) fjc[i] = fjc[i+1]*(i+1) %mod;
    }
    ll C(ll n,ll m){ return jc[n]*fjc[m]%mod*fjc[n-m]%mod; }
    ll A(ll n,ll m){ return jc[n]*fjc[n-m]%mod; }
}comb;
#define C(n,m) (comb.C(n,m))
#define A(n,m) (comb.A(n,m))
ll n,m;
char ch[N];
bool o[N]; ll s[N], ss[N];
ll f[N][N], ff[N][N], g[N][N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ll i,j,k,p;
    read(n), read(m);
    comb.init(n);
    scanf("%s",ch+1);
    fr(i,1,n) o[i] = ch[i]-'0';
    fr(i,1,n){ ll x; read(x); s[x]++; }
    ss[0] = s[0];
    fr(i,1,n) ss[i] = ss[i-1] + s[i];
    f[0][0] = 1;
    ll sum = 0;//chosen position
    fr(i,1,n){
        // printf("\n\n i = %lld\n",i);
        memset(ff,0,sizeof(ff));
        if (!o[i]){//all will be failed
            fr(j,0,i){
                fr(k,0,i-j) if (f[j][k]){
                    fr(p,0,min(k,s[j+1])){
                        ( ff[j+1][k-p] += f[j][k] * C(k,p)%mod * A(s[j+1],p) ) %=mod;
                    }
                }
            }
            fr(j,0,i) fr(k,0,i-j){
                f[j][k] = ff[j][k];
                // if (f[j][k]) printf("f[%lld][%lld] : %lld\n",j,k,f[j][k]);
            }
            continue;
        }
        //win
        fr(j,0,i) fr(k,0,i-j)
            pls(ff[j][k+1],f[j][k]);
        //loss
        fr(j,0,i){
            fr(k,0,i-j) if (f[j][k]){
                ll el = ss[j]-(sum-k);
                if (el>0){
                    ll v = f[j][k]*el %mod;
                    fr(p,0,min(k,s[j+1])){
                        ( ff[j+1][k-p] += v * C(k,p)%mod * A(s[j+1],p) ) %=mod;
                    }
                }
            }
        }
        fr(j,0,i) fr(k,0,i-j){
            f[j][k] = ff[j][k];
            // if (f[j][k]) printf("f[%lld][%lld] : %lld\n",j,k,f[j][k]);
        }
        sum++;
    }
    ll ans = 0;
    fr(j,0,n){
        if (n-j<m) continue;
        ll us = 0;
        fr(k,j+1,n) us += s[k];
        fr(k,0,n) if (f[j][k] && k<=us){
            ( ans += f[j][k] * A(us,k) ) %=mod;
        }
    }
    // printf("ans = %lld\n",ans);
    ans = ans * comb.jc[n-sum] %mod;
    ans = (ans%mod+mod)%mod, printf("%lld\n",ans);
    return 0;
}
//g++ employ.cpp -o a -Wall -O2 -std=c++11