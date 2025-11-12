#include<bits/stdc++.h>
using namespace std;
#define db(x...) fprintf(stderr,x)
#define f dp[now]
#define g dp[!now]
using ll=long long;
const int N=505;
const ll Q=998244353;
int n,m,s[N],c[N];
namespace T1{
    const int M=(1<<18)+5,T=20;
    ll dp[2][T][M];
    struct node{
        int u,s;
    };
    node stkk[2][M*T],*stk1=stkk[0],*stk2=stkk[1];
    int top1,top2,now;
    void shua(int u,int s,ll w){
        // db("shua %d %d %lld\n",u,s,w);
        if(dp[now][u][s]<0) stk1[++top1]={u,s},dp[now][u][s]=0;
        dp[now][u][s]+=w,dp[now][u][s]>=Q?dp[now][u][s]-=Q:0;
    }
    void slv(){
        memset(dp,-1,sizeof dp);
        dp[now][0][0]=1;
        stk1[++top1]={0,0};
        for(int i=0;i<n;++i){
            now=!now;
            swap(stk1,stk2),swap(top1,top2);
            while(top2){
                node u=stk2[top2--];
                // db("f(%d,%d,%d)=%lld\n",i,u.u,u.s,dp[!now][u.u][u.s]);
                for(int j=0;j<n;++j)
                    if(!(u.s>>j&1)){
                        // db("add %d\n",j);
                        shua(u.u+(!s[i]||u.u>=c[j]),u.s|(1<<j),dp[!now][u.u][u.s]);
                    }
                dp[!now][u.u][u.s]=-1;
            }
        }
        ll ans=0;
        while(top1){
            node u=stk1[top1--];
            if(u.s==(1<<n)-1&&u.u<=m) ans+=dp[now][u.u][u.s];
        }
        printf("%lld\n",ans%Q);
    }
}
namespace T2{
    ll dp[2][N][N];
    int w[N],sw[N];
    int now;

    ll qp(ll a,ll b){
        ll ans=1;
        for(;b;b>>=1,a=a*a%Q)
            if(b&1) ans=ans*a%Q;
        return ans;
    }
    ll fac[N],ifac[N];
    ll C(int n,int m){
        if(n<0||n<m) return 0;
        return fac[n]*ifac[m]%Q*ifac[n-m]%Q;
    }

    void init(){
        fac[0]=1;
        for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%Q;
        ifac[n]=qp(fac[n],Q-2);
        for(int i=n;i;--i) ifac[i-1]=ifac[i]*i%Q;
    }
    void slv(){
        init();
        for(int i=0;i<n;++i) ++w[c[i]];
        for(int i=n;i>=0;--i) sw[i]=sw[i+1]+w[i];
        ll ans=0;
        f[0][0]=1;
        for(int i=0;i<n;++i){
            now=!now;
            for(int j=0;j<=m;++j)
                for(int k=0;k+j<=m;++k){
                    f[j][k]+=g[j][k],f[j][k]>=Q?f[j][k]-=Q:0;
                    for(int t=0;t<=w[j]&&j+k+t<=m;++t){
                        if(!k&&!t) continue;
                        ll v=g[j][k]*C(i-j,w[j]-t)%Q;
                        f[j+1][k+t-1]+=v,f[j+1][k+t-1]>=Q?f[j+1][k+t-1]-=Q:0;
                        if(!(k+t-1)){
                            ans+=v*C(i-j,w[j+1])%Q*C(n-j-1-w[j+1],sw[j+2])%Q;
                        }
                    }
                    g[j][k]=0;
                }
            // for(int j=0;j<=m;++j)
            //     for(int k=0;k<=m;++k) db("f(%d,%d,%d)=%lld\n",i,j,k,f[j][k]);
        }
        printf("%lld\n",ans%Q);
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m,m=n-m;
    string str;
    cin>>str;
    for(int i=0;i<n;++i){
        s[i]=str[i]-'0';
    }
    for(int i=0;i<n;++i) cin>>c[i];
    if(n<=18) T1::slv();
    else T2::slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}