#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500010],e[500010][30],sum[30][500010],dp[500010],mi[30];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    mi[0]=1;
    for(int i=1;i<=20;i++){
        mi[i]=mi[i-1]*2;
    }
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        ll c=0;
        ll u=a[i];
        while(u){
            e[i][c++]=u%2;
            u/=2;
        }
    }
    for(int o=0;o<=20;o++){
        for(int i=1;i<=n;i++){
            sum[o][i]=sum[o][i-1]+e[i][o];
        }
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        for(int j=0;j<=i-1;j++){
            //j+1-i
            ll res=0;
            for(int o=0;o<=20;o++){
                if((sum[o][i]-sum[o][j])%2==1){
                    res=res+mi[o];
                }
            }
            if(res==k){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    printf("%lld",dp[n]);
    return 0;
}
