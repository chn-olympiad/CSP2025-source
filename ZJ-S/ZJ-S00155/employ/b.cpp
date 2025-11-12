#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=102,P=998244353;
inline void upd(int &x,ll y){x=(x+y)%P;}

int inv[N],fac[N],ifac[N],binom[N][N],cper[N][N];
int n,m,s[N],pre[N],a[N],cnt[N],suf[N],f[N][N][N];

int main(){
    inv[0]=inv[1]=fac[0]=ifac[0]=1;
    for(int i=2;i<N;i++)inv[i]=(ll)(P-P/i)*inv[P%i]%P;
    for(int i=1;i<N;i++)fac[i]=(ll)fac[i-1]*i%P,ifac[i]=(ll)ifac[i-1]*inv[i]%P;
    for(int i=0;i<N;i++)for(int j=binom[i][0]=1;j<=i;j++)binom[i][j]=(binom[i-1][j-1]+binom[i-1][j])%P;
    for(int i=0;i<N;i++)for(int j=0;j<=i;j++)cper[i][j]=(ll)fac[i]*ifac[i-j]%P;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%1d",s+i);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+!s[n-i+1];
    for(int i=1;i<=n;i++)scanf("%d",a+i),cnt[a[i]]++;
    for(int i=n;i>=1;i--)suf[i]=suf[i+1]+cnt[i];
    for(int i=0;i<=n-m;i++)for(int j=0;j<=n;j++)if(!pre[j])f[i][j][0]=cper[suf[i+1]][j];
    for(int i=n-1;i;i--)for(int j=0;j<n;j++)for(int k=0;k<=n;k++)if(f[i][j][k]){
        // fprintf(stderr,"solving %d %d %d\n",i,j,k);
        for(int nj=j+1;nj<=n;nj++){
            if(pre[nj]>pre[j+1])break;
            for(int o:{0,1})if(!s[n-j]||o){
                for(int dk=0;dk<=k;dk++){
                    int nk=k+o-dk;
                    int coef=cper[suf[i]-j+k-dk][nj-j-o];
                    // cerr<<coef<<endl;
                    coef=(ll)coef*(cper[cnt[i]][dk])%P;
                    upd(f[i-1][nj][nk],(ll)f[i][j][k]*coef);
                    // fprintf(stderr,"* %d -> f[%d][%d][%d] (o = %d, dk = %d)\n",coef,i-1,nj,nk,o,dk);
                }
            }
        }
    }
    // for(int i=n-1;i>=0;i--)for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)if(f[i][j][k])
    //     fprintf(stderr,"f[%d][%d][%d] = %d\n",i,j,k,f[i][j][k]);
    printf("%d\n",f[0][n][cnt[0]]);
    return 0;
}