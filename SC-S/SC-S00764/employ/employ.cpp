#include<bits/stdc++.h>
using namespace std;

const int N=550;
const int mod=998244353;
int n,m,a[N],b[N],st[N],fac[N],inv[N],f[N],pr[N];
char s[N];

// int qpow(int x,int y){
//     int ret=1;
//     while(y){
//         if(y&1) ret=1ll*ret*x%mod;
//         x=1ll*x*x%mod;
//         y>>=1;
//     }
//     return ret;
// }
void solve(int S){
    int res=1,c=0;
    for(int i=1,prv=0;i<=n;i++){
        if(s[i]=='1')
            st[i]=(S>>c&1);
        pr[i]=prv,prv+=(!st[i]);
    }
    for(int i=n;i>=1;i--){
        if(st[i])
            res=1ll*res*(b[pr[i]+1]-c)%mod,++c;
    }
    f[S]=1ll*res*fac[n-c]%mod;
    // printf("%d\n",f[S]);
}
int p[N];
int solve2(){
    iota(p+1,p+1+n,1);
    int ans=0;
    do{
        int c=0,r=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0') ++c;
            else if(a[p[i]]>c) ++r;
            else ++c;
        }
        if(r>=m) ans++;
    }while(next_permutation(p+1,p+1+n));
    return ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d%s",&n,&m,s+1),fac[0]=inv[0]=1;
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=s[i]-'0',fac[i]=1ll*fac[i-1]*i%mod;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[a[i]]++;
    
    if(cnt<m) return puts("0"),0;
    if(cnt>20) return puts("0"),0;
    if(n<=10){
        printf("%d\n",solve2());
        return 0;
    };
    for(int i=n;i>=0;i--) b[i]+=b[i+1];
    int ans=0; 
    for(int S=0;S<(1<<cnt);S++)
        solve(S);
    for(int S=0;S<(1<<cnt);S++){
        for(int T=(S+1)|S;T<(1<<cnt);T=(T+1)|S){
            int e=__builtin_popcount(S^T)&1?-1:1;
            f[S]=((long long)f[S]+mod+e*f[T])%mod;
            // cerr<<S<<" "<<T<<endl;
        }
        if(__builtin_popcount(S)>=m) (ans+=f[S])%=mod;
    }
    printf("%d\n",ans);
    return 0;
}