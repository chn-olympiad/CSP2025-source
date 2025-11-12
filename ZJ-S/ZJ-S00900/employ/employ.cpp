/*
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e2+5,mod=998244353;
int n,m,s_[maxn],c[maxn],f[(1<<18)+5][20],sum,fp[maxn][maxn];
char S[maxn];
int rd(){
    int res=0,y=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') y=-y;ch=getchar();}
    while(isdigit(ch)) res=(res<<1)+(res<<3)+(ch&15),ch=getchar();
    return res*y;
}
void calc(){
    f[0][0]=1;
    for(int s=0;s<(1<<n);s++){
        int num=__builtin_popcount(s);
        for(int j=0;j<=num;j++){
            for(int i=0;i<n;i++) if(!((s>>i)&1)&&f[s][j]){
                int I=i+1;
                int cot=num-j;
                if(cot<c[I]&&s_[num+1]==1) f[s|(1<<i)][j+1]=(f[s|(1<<i)][j+1]+f[s][j])%mod;
                else f[s|(1<<i)][j]=(f[s|(1<<i)][j]+f[s][j])%mod;
            }
            // printf("%lld %lld %lld\n",s,j,f[s][j]);
        }
    }
    int ans=0;
    for(int i=m;i<=n;i++) ans=(ans+f[(1<<n)-1][i])%mod;
    printf("%lld\n",ans);
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=rd();m=rd();
    scanf("%s",S+1);
    for(int i=1;i<=n;i++) s_[i]=S[i]-'0',sum+=s_[i];
    for(int i=1;i<=n;i++) c[i]=rd();
    // printf("%lld %lld\n",n,m);
    // for(int i=1;i<=n;i++) printf("%lld ",s_[i]);puts("");
    // for(int i=1;i<=n;i++) printf("%lld ",c[i]);puts("");
    if(n<=18){calc();return 0;}
    if(n==m){
        bool flg=1;
        for(int i=1;i<=n;i++) flg&=s_[i];
        for(int i=1;i<=n;i++) flg&=(c[i]>0);
        if(!flg){puts("0");return 0;}
        int ans=1;
        for(int i=1;i<=n;i++) ans=ans*i%mod;
        printf("%lld\n",ans);
    }
    return 0;
}