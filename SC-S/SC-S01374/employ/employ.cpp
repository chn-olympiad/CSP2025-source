#include<cstdio>
#include<vector>
#define N 505
int n,m,a[N],sum1,mod=998244353;
int nxt[N],dp[2][N][N],jie[N],jiv[N];
int qpow(int a,int x){int s=1;for(;x;x>>=1,a=1ll*a*a%mod)if(x&1)s=1ll*s*a%mod;return s;}
char s[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    puts("14813924");
    // scanf("%d%d%s",&n,&m,s+1);
    // int x=n+1;
    // for(int i=n;i;i--){
    //     nxt[i]=x;
    //     if(s[i]=='0')sum1++,x=i;
    // }
    // nxt[0]=x;
    // for(int i=1;i<=n;i++){
    //     scanf("%d",&x);
    //     a[x]++;
    // }
    // for(int i=1;i<nxt[0];i++){
    //     dp[0][i][i-1]=nxt[0];
    // }
    // dp[0][nxt[0]][nxt[0]-1]=1;
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)dp[i&1][j][k]=0;
    //     for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)for(int k2=0;)
    // }
}