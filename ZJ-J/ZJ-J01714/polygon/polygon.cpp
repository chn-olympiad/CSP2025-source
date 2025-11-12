#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long

using std::cin;
using std::vector;
using std::sort;
using std::cout;

const int mod=998244353;

int n,ans;
int a[5010];
int dp[500010];

signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dp[0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int t=a[i]+1; t<=n*a[n]; t++)
        {
            ans=(ans+dp[t])%mod;
        }
        for(int t=n*a[n]; t>=a[i]; t--)
        {
            dp[t]=(dp[t]+dp[t-a[i]])%998244353;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
