#include<bits/stdc++.h>
using namespace std;
int t,n,ans=-0x3f,a1[111111],a2[111111],a3[111111],dp[211][211][211];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t!=0)
    {
        t--;
        ans=-0x3f;
        memset(dp,0,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a1[i]>>a2[i]>>a3[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n/2;j++)
            {
                for(int k=0;k<=n/2;k++)
                {
                    if((i-1-j-k)<0)
                        continue;
                    if(j<=n/2)
                    {
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a1[i]);
                    }
                    if(k<=n/2)
                    {
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a2[i]);
                    }
                    if((i-1-j-k)<=n/2)
                    {
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a3[i]);
                    }
                }
            }
        }
        for(int i=1;i<=n/2;i++)
        {
            for(int j=1;j<=n/2;j++)
            {
                if((n-i-j)<=n/2)
                    ans=max(ans,dp[n][i][j]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
