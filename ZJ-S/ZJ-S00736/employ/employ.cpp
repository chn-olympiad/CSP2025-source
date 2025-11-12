#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int Mod=998244353;
const int INF=(1<<18)+5;
const int INFM=21;
const int INFN=505;
const int INFF=1e6+5;
int n,m,fav[INFF],ifav[INFF];
int ksm(int x,int y) {
    int ba=x%Mod,ans=1;
    while (y) {
        if (y&1) ans=(ans*ba)%Mod;
        ba=(ba*ba)%Mod;y>>=1;
    }
    return ans;
}
void init() {
    fav[0]=1;int N=1e6;
    for (int i=1;i<=N;i++) fav[i]=fav[i-1]*i%Mod;
    ifav[N]=ksm(fav[N],Mod-2);
    for (int i=N-1;~i;i--) ifav[i]=ifav[i+1]*(i+1)%Mod;
}
int C(int x,int y) {
    if (x<y) return 0;
    return fav[x]*ifav[y]%Mod*ifav[x-y]%Mod;
}
namespace Sub1{
    int f[2][INF][INFM];
    int c[INFM],s1[INFM];
    void main() {
        for (int i=0;i<n;i++) {
            char cc;cin>>cc;
            s1[i]=cc-'0';
        }
        for (int i=0;i<n;i++) cin>>c[i];
        f[1][0][0]=1;
        for (int i=0;i<n;i++) {
            int u=i&1,v=u^1;
            memset(f[u],0,sizeof f[u]);
            for (int s=0;s<(1<<n);s++) {
                if (__builtin_popcount(s)!=i) continue;
                // f[u][s][w]
                for (int w=0;w<=i;w++) {
                    for (int p=0;p<n;p++) {
                        if ((s>>p)&1) continue;
                        f[u][s|(1<<p)][w+(c[p]<=w || s1[i]==0)]+=f[v][s][w];
                        if (f[u][s|(1<<p)][w+(c[p]<=w || s1[i]==0)]>=Mod) 
                            f[u][s|(1<<p)][w+(c[p]<=w || s1[i]==0)]-=Mod;
                    }
                }
            }
        }
        // <=n-m
        int res=0;
        for (int w=0;w<=n-m;w++)
            res+=f[(n-1)&1][(1<<n)-1][w],res%=Mod;
        cout<<res<<"\n";
    }
}
int c[INFN],s1[INFN],f[INFN][INFN],ff[INFN],g[INFN],num[INFN];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m; init();
    if (n<=18) Sub1::main();
    else {
        int fl=0;
        for (int i=0;i<n;i++) {
            char cc;cin>>cc;
            s1[i]=cc-'0';
            if (s1[i]==0) fl=1;
        }
        int fl2=0;
        for (int i=0;i<n;i++) {
            cin>>c[i];
            if (c[i]==0) fl2=1;
        }
        if (m==n) {
            if (fl || fl2) {cout<<"0\n";return 0;}
            else {
                int ba=1;
                for (int w=1;w<=n;w++)
                    ba*=w,ba%=Mod;
                cout<<ba<<"\n";
                return 0;
            }
        }
        if (m==n) {
            sort(c,c+n);
            ff[0]=1;
            for (int i=1;i<n;i++) {
                for (int j=0;j<=i;j++) {
                    // f[i-1][j] 钦定 i-1 中有 j 个
                    // num[c[i]]+j 个空
                    ff[i]+=ff[i-1]*(num[c[i]]+j);
                    ff[i]%=Mod;
                }
            }
            int ba=1;
            for (int w=1;w<=n;w++)
                ba*=w,ba%=Mod;
            cout<<((ba-ff[n-1])%Mod+Mod)%Mod<<"\n";
            return 0;
        }
        if (!fl) {
            sort(c,c+n);int cntc=0;
            for (int w=1;w<=n;w++) cntc+=c[w]==0;
            for (int w=0;w<=n;w++) 
                if (w>=cntc) num[w]=cntc;
                else num[w]=w;
            f[cntc][0]=1;
            for (int i=cntc+1;i<n;i++) {
                for (int j=0;j<=i;j++) {
                    // f[i-1][j] 钦定 i-1 中有 j 个
                    // num[c[i]]+j 个空
                    f[i][j+1]+=f[i-1][j]*(num[c[i]]+j);f[i][j+1]%=Mod;
                    f[i][j]+=f[i-1][j];f[i][j]%=Mod;
                }
            }
            // cerr<<num[1]<<" "<<num[3]<<" "<<
            for (int i=0;i<=n;i++) g[i]=f[n-1][i]*C(n,i)%Mod*fav[n-i]%Mod;
            for (int i=n;i>=0;i--)
                for (int j=i-1;j>=0;j--)
                    g[j]-=g[i]*C(i,j),g[j]%=Mod,g[j]+=Mod,g[j]%=Mod;
            int ans=0;
            for (int i=m;i<=n;i++)
                ans+=g[i],ans%=Mod;
            cout<<ans<<"\n";
            return 0;
        }
    }
    return 0;
}