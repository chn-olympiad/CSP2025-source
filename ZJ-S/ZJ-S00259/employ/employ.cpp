#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(k,l,r) for(int k=l;k<=r;++k)
#define per(k,r,l) for(int k=r;k>=l;--k)
#define ll long long 
#define ull unsigned long long
#define PII pair<int,int>
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define ld double
#define cl(f,x) memset(f,x,sizeof(f))
using namespace std;
void file_IO() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
}
bool M1;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const ld eps=1e-9;
const int N=5e2+5,MOD=998244353;
char s[N];
int f[N][N][N],a[N],c[N],pre[N],p[N],n,m;
int jc[N],inv_jc[N];
int qpow(int a,int b) {
    int res=1,base=a;
    while(b) {
        if(b&1)
            res=1ll*res*base%MOD;
        base=1ll*base*base%MOD; b>>=1;
    }
    return res;
}
void add(int &a,int b) {
    a+=b;
    if(a>=MOD)
        a-=MOD;
}
int C(int n,int m) {
    if(m<0||n<m)
        return 0;
    return 1ll*jc[n]*inv_jc[n-m]%MOD*inv_jc[m]%MOD;
}
int P(int n,int m) {
    if(m<0||n<m)
        return 0;
    return 1ll*jc[n]*inv_jc[n-m]%MOD;
}
void solve() {
    scanf("%d%d",&n,&m);
    jc[0]=1;
    rep(i,1,n)
        jc[i]=1ll*jc[i-1]*i%MOD;
    inv_jc[n]=qpow(jc[n],MOD-2);
    per(i,n-1,0)
        inv_jc[i]=1ll*inv_jc[i+1]*(i+1)%MOD;
    scanf("%s",s+1);
    rep(i,1,n) {
        int x;
        scanf("%d",&x);
        ++c[x];
    }
    rep(i,0,n)
        p[i]=i;
    pre[0]=c[0];
    rep(i,1,n)
        pre[i]=pre[i-1]+c[i];
    f[0][0][0]=1;
    rep(i,1,n) {
        rep(j,0,i-1) {
            rep(k,0,i-1) { // cnt of > j
                if(!f[i-1][j][k])
                    continue;
                if(s[i]==48) {
                    rep(t,0,min(k,c[j+1])) { // cnt of = j+1
                        // > j+1
                        add(f[i][j+1][k-t+1],1ll*f[i-1][j][k]*C(k,t)%MOD*P(c[j+1],t)%MOD);
                        if(pre[j+1]>=i-1-(k-t)) // <= j+1
                            add(f[i][j+1][k-t],1ll*f[i-1][j][k]*C(k,t)%MOD*P(c[j+1],t)%MOD*(pre[j+1]-(i-1-(k-t)))%MOD);
                    }
                } else {
                    // <= j
                    rep(t,0,min(k,c[j+1])) { // cnt of = j+1
                        if(pre[j]>=i-1-k)
                            add(f[i][j+1][k-t],1ll*f[i-1][j][k]*C(k,t)%MOD*P(c[j+1],t)%MOD*(pre[j]-(i-1-k))%MOD);
                    }
                    // > j
                    add(f[i][j][k+1],f[i-1][j][k]);
                }
            }
        }
        // rep(j,0,i) {
        //     rep(k,0,i) {
        //         if(f[i][j][k])
        //             debug("(%d,%d,%d) = %d\n",i,j,k,f[i][j][k]);
        //     }
        // }
    }
    int res=0;
    rep(j,0,n-m)
        add(res,1ll*f[n][j][n-pre[j]]*jc[n-pre[j]]%MOD);
    printf("%d\n",res);
}
bool M2;
// g++ employ.cpp -std=c++14 -Wall -O2 -o employ
signed main() {
    file_IO();
    int testcase=1;
    // scanf("%d",&testcase);
    while(testcase--)
        solve();
    // debug("used time = %dms\n",(signed)(1000*clock()/CLOCKS_PER_SEC));
    // debug("used memory = %dMB\n",(signed)((&M2-&M1)/1024/1024));
    return 0;
}