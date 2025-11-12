#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=998244353;
int n,ans;
int a[5005];
int c[5005][5005];
bool flag=1;
signed main(){
    //freopen("polygon3.in","r",stdin);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1) flag=0;
    }
    if(flag){
        c[0][0]=1;
        for(int i=1;i<=n;i++){
            c[i][0]=1;
            for(int j=1;j<=n;j++){
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
            }
        }
        for(int i=3;i<=n;i++){
            ans=(ans+c[n][i])%mod;
        }
    }else{
        for(int i=0;i<(1<<n);i++){
            int mx=0,sum=0,summ=0;
            for(int j=1;j<=n;j++){
                if((i>>(j-1))&1){
                    summ++;
                    sum+=a[j];
                    mx=max(mx,a[j]);
                }
            }
            if(summ<3) continue;
            if(sum>mx*2){
                ans++;
                ans%=mod;
            }
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
