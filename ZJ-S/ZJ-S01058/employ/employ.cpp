#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
inline void add(int &x,int y){
    x+=y;
    if(x>=mod) x-=mod;
}
inline int read(){
    int w=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) w=w*10+ch-'0',ch=getchar();
    return w;
}
inline int gc(){
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    return ch-'0';
}
const int N=505;
int n,m;
int s[N],pre[N];
int c[N],ton[N],preton[N];
int f[N][N],g[N][N],h[N][N];
int dp[N];
int C[N][N];
int fac[N];
main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        s[i]=gc();
        pre[i]=pre[i-1]+(s[i]^1);
    }
    for(int i=1;i<=n;i++) ton[c[i]=read()]++;
    preton[0]=ton[0];
    for(int i=1;i<=n;i++) preton[i]=ton[i]+preton[i-1];
    f[0][0]=1;
    for(int i=0;i<=n;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    for(int i=1;i<=n;i++){
        memset(g,0,sizeof(g));memset(h,0,sizeof(h));
        if(s[i]){
            for(int j=pre[i-1];j<=i-1;j++){
                // printf("preton %d %d\n",j,preton[j]);
                for(int k=0;k<=preton[j];k++){
                    //neng guo
                    // printf("same chuan %d %d\n",j,k);
                    add(g[j][k],f[j][k]);
                    //bu neng guo
                    for(int cs=0;cs<=ton[j+1]&&cs<=i-1-k;cs++) add(g[j+1][k+cs+1],f[j][k]*C[i-1-k][cs]%mod*C[ton[j+1]][cs]%mod*fac[cs]%mod*(preton[j]-k)%mod);
                }
            }
        }else{
            for(int j=pre[i-1];j<=i-1;j++){
                for(int k=0;k<=preton[j];k++){
                    //bu neng guo
                    for(int cs=0;cs<=ton[j+1]&&cs<=i-1-k;cs++){
                        //<= j
                        add(g[j+1][k+cs+1],f[j][k]*C[i-1-k][cs]%mod*C[ton[j+1]][cs]%mod*fac[cs]%mod*(preton[j]-k)%mod);
                        // =j+1
                        if(cs<ton[j+1])
                        add(g[j+1][k+cs+1],f[j][k]*C[i-1-k][cs]%mod*C[ton[j+1]][cs+1]%mod*fac[cs+1]%mod);
                        //>j+1
                        add(g[j+1][k+cs],f[j][k]*C[i-1-k][cs]%mod*C[ton[j+1]][cs]%mod*fac[cs]%mod);
                    }
                }
            }
        }
        memcpy(f,g,sizeof(f));
        // for(int j=0;j<=i;j++){
        //     for(int k=0;k<=i;k++){
        //         if(!f[j][k]) continue;
        //         printf("%lld %lld %lld %lld\n",i,j,k,f[j][k]);
        //     }
        // }
    }
    int ans=0;
    for(int j=0;j<=n-m;j++){
        int cnt=0;
        for(int k=j+1;k<=n;k++) cnt+=ton[k];
        int k=n-cnt;
        add(ans,fac[cnt]*f[j][k]%mod);
    }
    printf("%lld\n",ans);
}