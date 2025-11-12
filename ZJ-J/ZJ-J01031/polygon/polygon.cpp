#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,a[5001],dp[5001][5002],ans=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    dp[1][a[1]]=1;
    dp[1][0]=1;
    for(int i = 1;i < n;i++)
    {
        for(int j = 0;j <= 5000;j++)
        {
            dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
            dp[i+1][min(5000,j+a[i+1])]=(dp[i+1][min(5000,j+a[i+1])]+dp[i][j])%mod;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = a[i]+1;j <= 5000;j++)
        {
            ans = (ans+dp[i-1][j])%mod;
        }
    }
    cout << ans;
    return 0;
}