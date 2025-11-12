#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=510;
const int M=110;
const int mod=998244353;
int n,m;
char s[N];
int c[N];
int fact[N],infact[N];
int p[N];
int qmi(int x,int k){
    int res=1;
    while(k){
        if(k&1) res=(LL)res*x%mod;
        x=(LL)x*x%mod;
        k>>=1;
    }
    return res;
}
void init(int n){
    fact[0]=infact[0]=1;
    for(int i=1;i<=n;i++) fact[i]=(LL)fact[i-1]*i%mod;
    infact[n]=qmi(fact[n],mod-2);
    for(int i=n-1;i;i--) infact[i]=(LL)infact[i+1]*(i+1)%mod;
    return;
}
LL C(int n,int m){
    if(n<m) return 0;
    return (LL)fact[n]*infact[m]%mod*infact[n-m]%mod;
}
LL A(int n,int m){
    if(n<m) return 0;
    return (LL)fact[n]*infact[m]%mod;
}
namespace stk1{
    void main(){
        LL ans=0,sum=1,cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='1'){
                cnt++;
                // cout<<sum<<" "<<n-p[i-1]<<" "<<fact[n-cnt]<<endl;
                ans=(ans+sum*(n-p[i-1])%mod*fact[n-cnt]%mod)%mod;
                sum=sum*(p[i-1]-cnt+1)%mod;
            }
        }
        printf("%lld\n",ans);
        return;
    }
}
namespace stk2{
    void main(){
        if(c[1]==0) puts("0");
        else printf("%d\n",fact[n]);
        return;
    }
}
void add(int &x,int y){
    if(x+y>mod) x+=y-mod;
    else x+=y;
    return;
}
namespace stk3{
    int f[1<<18][20];
    int cnt[1<<18];
    void main(){
        for(int i=1;i<(1<<n);i++) cnt[i]=cnt[i>>1]+(i&1);
        f[0][0]=1;
        for(int i=0;i<(1<<n);i++)
            for(int j=0;j<=cnt[i];j++){
                if(!f[i][j]) continue;
                if((n-cnt[i]+j)<m) continue;
                // cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
                for(int k=0;k<n;k++)
                    if(!(i>>k&1)){
                        if(s[cnt[i]+1]=='1' && c[k+1]>cnt[i]-j)
                            add(f[i|(1<<k)][j+1],f[i][j]);
                        else add(f[i|(1<<k)][j],f[i][j]);
                    }
            }
        int ans=0;
        for(int i=m;i<=n;i++) add(ans,f[(1<<n)-1][i]);
        printf("%d\n",ans);
        return;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    init(N-5);
    // cerr<<C(6,3)<<" "<<C(4,2)<<endl;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    sort(c+1,c+n+1);
    // for(int i=1;i<=n;i++) p[i]=n;
    for(int i=1;i<=n;i++) p[c[i]]=i;
    for(int i=1;i<=n;i++) p[i]=max(p[i-1],p[i]);
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=(s[i]=='1');
    if(cnt<m){
        puts("0");
        return 0;
    }
    // cerr<<cnt<<endl;
    if(m==1) {stk1::main();return 0;}
    if(m==n) {stk2::main();return 0;}
    if(n<=18){stk3::main();return 0;}
    return 0;
}//g++ employ.cpp -o a -O2