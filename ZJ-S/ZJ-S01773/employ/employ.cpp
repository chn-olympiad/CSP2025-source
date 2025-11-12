#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL p=998244353,N=505;
LL f[N][N],g[N][N],cn[N],n,m,qz[N],C[N][N],fc[N],hz[N],an;string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m>>s;
    for(LL i=1,x;i<=n;++i)cin>>x,++cn[x];
    qz[0]=cn[0];
    for(LL i=1;i<=n;++i)qz[i]=qz[i-1]+cn[i];
    hz[n]=cn[n];
    for(LL i=n-1;i>=0;--i)hz[i]=hz[i+1]+cn[i];
    f[0][0]=1;
    for(LL i=0;i<=n;++i)
    for(LL j=C[i][0]=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
    for(LL i=fc[0]=1;i<=n;++i)fc[i]=fc[i-1]*i%p;
    for(LL i=0;i<n;++i){
        memset(g,0,sizeof(g));
        for(LL j=0;j<=n;++j)for(LL k=0;k<=n;++k)if(f[j][k]&&hz[j+1]>=k&&qz[j]>=i-k)
        if(s[i]=='1'){
            g[j][k+1]=(g[j][k+1]+f[j][k])%p;
            for(LL l=k;l>=0&&l>=k-cn[j+1];--l)g[j+1][l]=(g[j+1][l]+f[j][k]*C[cn[j+1]][k-l]%p*C[k][l]%p*fc[k-l]%p*(qz[j]-(i-k)))%p;
        }else{
            for(LL l=k;l>=0&&l>=k-cn[j+1];--l){
                g[j+1][l]=(g[j+1][l]+f[j][k]*C[cn[j+1]][k-l]%p*C[k][l]%p*fc[k-l]%p*(qz[j]-(i-k)))%p;
                if(cn[j+1])g[j+1][l]=(g[j+1][l]+f[j][k]*C[cn[j+1]-1][k-l]%p*C[k][l]%p*fc[k-l]%p*cn[j+1])%p;
                g[j+1][l+1]=(g[j+1][l+1]+f[j][k]*C[cn[j+1]][k-l]%p*C[k][l]%p*fc[k-l])%p;
            }
        }
        memcpy(f,g,sizeof(f));
    }
    for(LL j=0;j<=n-m;++j)for(LL k=0;k<=n;++k)if(f[j][k]&&hz[j+1]>=k&&qz[j]>=n-k)
    an=(an+f[j][k]*fc[k])%p;
    printf("%lld\n",an);return 0;
}