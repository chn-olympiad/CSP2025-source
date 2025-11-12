#include <bits/stdc++.h>
using namespace std;
const int N=510;
const int Mod=998244353;
typedef long long ll;

int n,m;
int a[N];
int cnt[N],pre[N],suf[N];
int f[2][N][N];
int C[N][N],fac[N];

int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
    for(int i=1;i<=n;i++) {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    pre[0]=cnt[0];
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+cnt[i];
    for(int i=n;i>=0;i--) suf[i]=suf[i+1]+cnt[i];
    C[0][0]=1;
    fac[0]=1;
    for(int i=1;i<=n;i++) {
        fac[i]=1ll*fac[i-1]*i%Mod;
        C[i][0]=1;
        for(int j=1;j<=i;j++) {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
        }
    }
    int now=0;
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) f[0][i][j]=0;
    f[0][0][0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) f[now^1][j][k]=0;
        if(a[i]) {
            for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) if(f[now][j][k]) {
                f[now^1][j][k+1]=(f[now^1][j][k+1]+f[now][j][k])%Mod;
                if(i-1-k<pre[j]) {
                    int val=1ll*f[now][j][k]*(pre[j]-(i-1-k))%Mod;
                    for(int x=0;x<=cnt[j+1] && x<=k;x++) {
                        f[now^1][j+1][k-x]=(f[now^1][j+1][k-x]+1ll*val*C[k][x]%Mod*fac[x]%Mod*C[cnt[j+1]][x]%Mod)%Mod;
                    }
                }
            }
        }
        else {
            for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) if(f[now][j][k]) {
                for(int x=0;x<=cnt[j+1] && x<=k;x++) {
                    int val=1ll*f[now][j][k]*C[k][x]%Mod*fac[x]%Mod*C[cnt[j+1]][x]%Mod;
                    f[now^1][j+1][k-x+1]=(f[now^1][j+1][k-x+1]+val)%Mod;
                    if(i-1-(k-x)<pre[j+1]) f[now^1][j+1][k-x]=(f[now^1][j+1][k-x]+1ll*val*(pre[j+1]-(i-1-(k-x)))%Mod)%Mod;
                }
            }
        }
        now^=1;
    }
    int ans=0;
    for(int i=0;n-i>=m;i++) for(int j=0;j<=n && j<=suf[i+1];j++) if(f[now][i][j]) {
        ans=(ans+1ll*f[now][i][j]*fac[j]%Mod)%Mod;
    }
    printf("%d",ans);
    return 0;
}
//15:53