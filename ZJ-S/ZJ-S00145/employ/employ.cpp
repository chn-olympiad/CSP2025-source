#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
const int mod=998244353;
int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while( isdigit(ch)){ret=(ret<<3)+(ret<<1)+(ch&15);ch=getchar();}
    return ret*f;
}
int n,m;
char s[maxn];
int c[maxn];
namespace Sub1{
    int p[maxn];
    void main(){
        int ans=0;
        for(int i=1;i<=n;++i) p[i]=i;
        do{ 
            int cnt=0;
            for(int i=1;i<=n;++i){
                if(s[i]=='0'||c[p[i]]<=cnt){
                    cnt++;
                }
            }
            if(cnt<=n-m) ans++;
        }while(next_permutation(p+1,p+n+1));
        printf("%d\n",ans);
    }
}
namespace Sub2{
    void main(){
        int ans=1;
        for(int i=1;i<=n;++i) ans=1ll*ans*i%mod;
        for(int i=1;i<=n;++i){
            if(s[i]=='0'||c[i]==0){
                ans=0;
            }
        }
        printf("%d\n",ans);
    }
}
int cnt=0;
namespace Sub3{
    vector<int> P[maxn];
    int cnt[maxn],fac[maxn],inv[maxn];
    void main(){
        fac[0]=1;
        for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
        for(int i=1;i<=n;++i) cnt[c[i]]++;
        int cur=cnt[0],ans=1;
        for(int i=1;i<=n;++i){
            if(s[i]=='1'){
                ans=1ll*ans*cur%mod;
                cur--;
            }
            cur+=cnt[i];
        }
        ans=1ll*ans*fac[cur]%mod;
        ans=(fac[n]-ans+mod)%mod;
        printf("%d\n",ans);
    }
}
namespace Sub4{
    const int maxS=(1<<18)+5;
    int f[maxS][maxn],S,sta[maxn];
    void main(){
        f[0][0]=1;S=(1<<n)-1;
        for(int i=1;i<=n;++i) sta[i]=s[i]-'0';
        for(int s=1;s<=S;++s){
            int cnt=__builtin_popcount(s);
            for(int i=1;i<=n;++i){
                if(!(s&(1<<(i-1)))) continue;
                int ts=s^(1<<(i-1));
                if(sta[cnt]==0){
                    for(int t=0;t<n;++t){
                        f[s][t+1]=(f[s][t+1]+f[ts][t])%mod;
                    }
                }else{
                    for(int t=0;t<c[i];++t){
                        f[s][t]=(f[s][t]+f[ts][t])%mod;
                    }
                    for(int t=c[i];t<n;++t){
                        f[s][t+1]=(f[s][t+1]+f[ts][t])%mod;
                    }
                }
            }
        }
        int ans=0;
        for(int t=0;t<=n-m;++t) ans=(ans+f[S][t])%mod;
        printf("%d\n",ans);
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    scanf("%s",s+1);
    for(int i=1;i<=n;++i) c[i]=read();
    for(int i=1;i<=n;++i){
        if(s[i]=='1'){
            cnt++;
        }
    }
    if(n<=10){
        Sub1::main();
    }else if(n<=18){
        Sub4::main();   
    }else if(n==m){
        Sub2::main();
    }else if(m==1){
        Sub3::main();
    }else if(cnt<m){
        printf("0\n");
    }else{
        int ans=1;
        for(int i=1;i<=n;++i) ans=1ll*ans*i%mod;
        printf("%d\n",ans);
    }
    return 0;
}