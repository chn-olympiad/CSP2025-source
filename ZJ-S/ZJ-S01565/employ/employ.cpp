#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l),qwp=(r);i<=qwp;i++)
#define per(i,r,l) for(int i=(r),qwp=(l);i>=qwp;i--)
using namespace std;
namespace ax_by_c{
typedef long long ll;
constexpr ll mod=998244353;
int frint(){int n=0;char c=getchar();while(c<'0'||'9'<c)c=getchar();while('0'<=c&&c<='9')n=n*10+c-48,c=getchar();return n;}
int fr01(){char c=getchar();while(c<'0'||'1'<c)c=getchar();return c-'0';}
void wrll(ll x){if(x>9)wrll(x/10);putchar(x%10+48);}
int n,m,s[505],c[505];
namespace Sub1{
constexpr int N=20;
constexpr int S=(1<<18)+5;
inline void add(ll &x,ll y){x=(x+y)%mod;}
int pct[S];
ll f[S][N];
void main(){
    rep(s,0,(1<<n)-1)pct[s]=pct[s>>1]+(s&1);
    add(f[0][0],1);
    rep(ss,0,(1<<n)-2)rep(i,0,n-1){
        rep(j,1,n)if(!(ss&(1<<(j-1)))){
            int v=ss|(1<<(j-1)),w=0;
            if(!s[pct[v]]||i>=c[j])w=1;
            add(f[v][i+w],f[ss][i]);
        }
    }
    ll ans=0;
    rep(i,0,n)if(n-i>=m)add(ans,f[(1<<n)-1][i]);
    wrll(ans),putchar('\n');
}
}
namespace Sub2{
constexpr int N=105;
inline void add(ll &x,ll y){x=(x+y)%mod;}
ll ksm(ll a,ll b,ll p){a=a%p;ll r=1;while(b){if(b&1)r=r*a%p;a=a*a%p,b>>=1;}return r%p;}
ll fac[N],inv[N];
void Init(int n){
    fac[0]=1;rep(i,1,n)fac[i]=fac[i-1]*i%mod;
    inv[n]=ksm(fac[n],mod-2,mod);per(i,n,1)inv[i-1]=inv[i]*i%mod;
}
ll C(int n,int m){if(n<m||m<0)return 0;return fac[n]*inv[m]%mod*inv[n-m]%mod;}
ll A(int n,int m){if(n<m||m<0)return 0;return C(n,m)*fac[m]%mod;}
int cnt[N];
ll f[N][N][N],g[N][N];
void main(){
    Init(n);
    rep(i,1,n)cnt[c[i]]++;rep(i,1,n)cnt[i]+=cnt[i-1];
    if(!cnt[0])return (void)(wrll(fac[n]),putchar('\n'));
    ll ans=0;
    rep(i,1,n)add(f[i][0][0],cnt[0]);
    rep(i,1,n){
        rep(j,0,i-1)rep(k,0,i-j-1)add(f[i][j][k],g[j][k]);
        rep(j,0,i-1){
            rep(k,0,i-j-1){
                if(n-j-1>=m)add(ans,f[i][j][k]*A(n-cnt[j+1],n-i)%mod*A(n-cnt[j]-(n-i),i-j-k-1)%mod);
                if(cnt[j+1]<(j+k+1))continue;
                rep(q,0,i-j-k-1){
                    add(g[j+1][k+q],f[i][j][k]*A(cnt[j+1]-cnt[j],q+1)%mod*C(i-j-k-1,q)%mod);
                    add(g[j+1][k+q],f[i][j][k]*(cnt[j]-(j+k+1))%mod*A(cnt[j+1]-cnt[j],q)%mod*C(i-j-k-1,q)%mod);
                }
            }
        }
    }
    wrll(ans),putchar('\n');
}
}
void main(){
    n=frint(),m=frint();
    rep(i,1,n)s[i]=fr01();
    rep(i,1,n)c[i]=frint();
    if(n<=18)return Sub1::main();
    bool F=0;rep(i,1,n)if(!s[i])F=1;if(!F&&n<=100)return Sub2::main();
}
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ax_by_c::main();
    return 0;
}
/*
ulimit -s 524288
g++ -O2 -std=c++14 -static employ.cpp -o employ.exe
g++ -O2 -std=c++14 -static -Wall -Wextra employ.cpp -o employ.exe
g++ -O2 -std=c++14 -Wall -Wextra -fsanitize=address,leak,undefined employ.cpp -o employ.exe
./employ.exe
*/