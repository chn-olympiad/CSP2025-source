#include<bits/stdc++.h>
using namespace std;

// #define int ll
#define file(jzc) freopen(#jzc".in","r",stdin),freopen(#jzc".out","w",stdout)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define LB lower_bound
#define UB upper_bound
#define all(a) (a).begin(),(a).end()

using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
using tiii=tuple<int,int,int>;
using vi=vector<int>;
using vvi=vector<vi>;

template<typename T1,typename T2>
void chkmin(T1&x,const T2&y){if(y<x)x=y;}
template<typename T1,typename T2>
void chkmax(T1&x,const T2&y){if(x<y)x=y;}

constexpr int mod=998244353;

int f[505][505][505];
int c[505],s[505];
bool a[505];
int fac[505],invf[505];
int n,m;

inline void add(int&x,const ll&y){x=(x+y)%mod;}

int qpow(int x,int y=mod-2){
    int ans=1;
    while(y)(y&1)&&(ans=(ll)ans*x%mod),x=(ll)x*x%mod,y>>=1;
    return ans;
}

int A(int n,int m){return n<m||m<0?0:(ll)fac[n]*invf[n-m]%mod;}
int C(int n,int m){return n<m||m<0?0:(ll)fac[n]*invf[n-m]%mod*invf[m]%mod;}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=c-'0';
    }
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
    invf[n]=qpow(fac[n]);
    for(int i=n-1;~i;i--)invf[i]=(ll)invf[i+1]*(i+1)%mod;
    for(int i=1,x;i<=n;i++)cin>>x,c[x]++,s[x]++;
    for(int i=1;i<=n;i++)s[i]+=s[i-1];
    f[0][0][0]=1;
    for(int i=1;i<=n;i++){
        if(a[i]){
            for(int j=0;j<i;j++)for(int k=0;k<=n;k++)if(f[i-1][j][k]){
                add(f[i][j][k],f[i-1][j][k]);
                for(int v=0;v<=c[j+1];v++){
                    if(k+v>n+2)continue;
                    add(f[i][j+1][k+v+1],(ll)f[i-1][j][k]*(s[j]-k)%mod*A(i-1-k,v)%mod*C(c[j+1],v));
                }
            }
        }else{
            for(int j=0;j<i;j++)for(int k=0;k<=n;k++)if(f[i-1][j][k]){
                for(int v=0;v<=c[j+1];v++){
                    if(k+v>n+2)continue;
                    add(f[i][j+1][k+v],(ll)f[i-1][j][k]*A(i-1-k,v)%mod*C(c[j+1],v));
                    add(f[i][j+1][k+v+1],(ll)f[i-1][j][k]*A(i-1-k,v)%mod*(s[j]-k)%mod*C(c[j+1],v));
                    if(v>0)add(f[i][j+1][k+v],(ll)f[i-1][j][k]*A(i-1-k,v-1)%mod*C(c[j+1],v)%mod*v);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n-m;i++)if(f[n][i][s[i]])add(ans,(ll)f[n][i][s[i]]*fac[n-s[i]]);
    cout<<ans<<'\n';
}

signed main(){
    file(employ);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
}


/*
16:07 pass pretest

wo shuang !!!!!!
*/