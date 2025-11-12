#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=505,MOD=998244353;
int n,m,c[N],p[N],buc[N],pre[N],suf[N];
char s[N];
i64 f[N][N],fac[N];
void Work(){
    cin>>n>>m>>(s+1);
    for(int i=1;i<=n;++i) cin>>c[i];
    if(m==n){
        for(int i=1;i<=n;++i){
            if(s[i]=='0'){
                puts("0");
                return ;
            }
        }
        fac[0]=1;
        for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%MOD;
        for(int i=1;i<=n;++i) ++buc[c[i]];
        for(int i=1;i<=n;++i) pre[i]=pre[i-1]+buc[i];
        for(int i=n;i;--i) suf[i]=suf[i+1]+buc[i];
        f[buc[0]][0]=1;
        i64 ans=0;
        for(int i=1;i<=n;++i){
            for(int j=0;j<=n;++j){
                for(int k=0;k<=n;++k){
                    (f[j][k+1]+=f[j][k])%=MOD;
                }
            }
            if(i-1<=n-m) (ans+=f[0][suf[i]]*fac[suf[i]])%=MOD;
            for(int j=0;j<=n;++j){
                for(int k=0;k<=n;++k){
                    if(j) f[j-1][k]=f[j][k]*j%MOD;
                    f[j][k]=0;
                }
            }
            // if(i<=n-m) (ans+=f[0][suf[i]]*fac[suf[i]])%=MOD;
            for(int t=buc[i];t--;){
                for(int j=n;j>=0;--j){
                    for(int k=0;k<=n;++k){
                        (f[j+1][k]+=f[j][k])%=MOD;
                        if(k) (f[j][k-1]+=f[j][k]*k)%=MOD;
                        f[j][k]=0;
                    }
                }
            }
        }
        // (ans+=f[0][0])%=MOD;
        printf("%lld\n",(ans+MOD)%MOD);
    }else if(n<=10){
        for(int i=1;i<=n;++i) p[i]=i;
        int ans=0;
        do{
            int cnt=0;
            for(int i=1;i<=n;++i){
                cnt+=(s[i]=='1'&&i-cnt-1<c[p[i]]);
            }
            ans+=(cnt>=m);
        }while(next_permutation(p+1,p+n+1));
        printf("%d\n",ans);
    }else{
        fac[0]=1;
        for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%MOD;
        for(int i=1;i<=n;++i) ++buc[c[i]];
        for(int i=1;i<=n;++i) pre[i]=pre[i-1]+buc[i];
        for(int i=n;i;--i) suf[i]=suf[i+1]+buc[i];
        f[buc[0]][0]=1;
        i64 ans=0;
        for(int i=1;i<=n;++i){
            for(int j=0;j<=n;++j){
                for(int k=0;k<=n;++k){
                    (f[j][k+1]+=f[j][k])%=MOD;
                }
            }
            if(i-1<=n-m) (ans+=f[0][suf[i]]*fac[suf[i]])%=MOD;
            for(int j=0;j<=n;++j){
                for(int k=0;k<=n;++k){
                    if(j) f[j-1][k]=f[j][k]*j%MOD;
                    f[j][k]=0;
                }
            }
            // if(i<=n-m) (ans+=f[0][suf[i]]*fac[suf[i]])%=MOD;
            for(int t=buc[i];t--;){
                for(int j=n;j>=0;--j){
                    for(int k=0;k<=n;++k){
                        (f[j+1][k]+=f[j][k])%=MOD;
                        if(k) (f[j][k-1]+=f[j][k]*k)%=MOD;
                        f[j][k]=0;
                    }
                }
            }
        }
        // (ans+=f[0][0])%=MOD;
        printf("%lld\n",(ans+MOD)%MOD);
    }
}
int main(){
    freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    Work();
    fclose(stdin),fclose(stdout);
    return 0;
}