#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x;
}
inline char readc(){
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    return ch-'0';
}
const int N=505,mod=998244353;
inline void upd(int &x,int y){x+=y;if(x>=mod)x-=mod;}
inline int add(int x,int y){return upd(x,y),x;}
int n,m,s[N],pres[N],c[N],b[N],f[2][N][N],fac[N];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)
        s[i]=readc(),pres[i]=pres[i-1]+s[i];
    fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
    for(int i=1;i<=n;i++)
        c[i]=read(),b[c[i]]++;
    for(int i=1;i<=n;i++)
        b[i]+=b[i-1];
    for(int i=m;i<=n;i++)
        f[0][0][n-i]=1;//(i&1?mod-1:1);
    for(int i=1;i<=n;i++){
        int p=n-i+1;
        int nw=i&1,lst=nw^1;
        memset(f[nw],0,sizeof(f[nw]));
        if(s[p]==0){
            for(int j=0;j<=n;j++)
                for(int k=1;k<=n;k++)
                    upd(f[nw][j][k-1],f[lst][j][k]);
            continue;
        }
        for(int j=0;j<=n;j++)for(int k=0,w;k<=n;k++)if(w=f[lst][j][k]){
            {
                int cnt=n-b[k]-j;
                if(cnt>0){
                    upd(f[nw][j+1][k],w*cnt%mod);
                }
            }
            if(k){
                upd(f[nw][j][k-1],w);
                int cnt=n-b[k-1]-j;
                if(cnt>0){
                    upd(f[nw][j+1][k-1],mod-w*cnt%mod);
                }
            }
        }
        // cerr<<"---"<<i<<"---\n";
        // for(int j=0;j<=n;j++){
        //     for(int k=0;k<=n;k++){
        //         cerr<<f[nw][j][k]<<' ';
        //     }
        //     cerr<<'\n';
        // }
    }
    // for(int j=0;j<=n;j++){
    //     for(int k=0;k<=n;k++){
    //         cerr<<f[n&1][j][k]<<' ';
    //     }
    //     cerr<<'\n';
    // }
    int ans=0;
    for(int j=m;j<=n;j++)
        upd(ans,f[n&1][j][0]*fac[n-j]%mod);
    printf("%lld\n",ans);
    return 0;
}