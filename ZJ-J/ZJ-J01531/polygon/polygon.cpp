#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P=998244353;
ll n,a[5010],sum,c[5010],ans;
inline void dfs(ll x){
    if(x==n+1){
        ll cnt=0,s=0,ma=0;
        for(int i=1;i<=n;i++){
            if(c[i]==1){
                cnt++;
                s+=a[i];
                ma=max(ma,a[i]);
            }
        }
        if(cnt>=3&&2*ma<s){
            ans++;
            ans%=P;
        }
        return;
    }
    c[x]=0;
    dfs(x+1);
    c[x]=1;
    dfs(x+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    if(sum==n&&n>20){
        ll r1=0,r2=1;
        for(int i=1;i<n;i++){
            r1+=i;
            r1%=P;
        }
        for(int i=1;i<=n;i++){
            r2*=2;
            r2%=P;
        }
        ll qans=r2;
        qans=(qans-1+P)%P;
        qans=(qans-n+P)%P;
        qans=(qans-r1+P)%P;
        printf("%lld",qans);
        return 0;
    }
    dfs(1);
    printf("%lld",ans);
    return 0;
}
