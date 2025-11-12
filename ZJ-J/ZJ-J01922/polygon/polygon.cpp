#include<bits/stdc++.h>
using namespace std;
const int tt=998244353;
int n,m,ans,a[5005],f[5005][5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);f[0][0]=1;m=a[n];
    for(int i=1,sum=1;i<=n;i++,sum=2ll*sum%tt){
        ans=((ans+sum)%tt+tt)%tt;
        for(int j=a[i];j>=0;j--)ans=((ans-f[i-1][j])%tt+tt)%tt;
        for(int j=0;j<=m;j++){
            f[i][j]=f[i-1][j];
            if(j>=a[i])f[i][j]=(f[i][j]+f[i-1][j-a[i]])%tt;
        }
    }
    cout<<ans;
    return 0;
}
