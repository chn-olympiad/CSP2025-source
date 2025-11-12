#include<bits/stdc++.h>
using namespace std;
int n,k,b[500050];
int dp[500050];
int ans=-1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	b[0]=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		b[i]=b[i-1]^x;
		dp[i]=0;
    }
    
    dp[0]=0;
    for(int r=1;r<=n;r++)
    {
    	for(int l=r;l>=1&&dp[l-1]+1>ans;l--)
    	{
    		if((b[r]^b[l-1])==k)
    		{
    			dp[r]=dp[l-1]+1;
    			break;
			}
		}
		dp[r]=max(dp[r],ans);
		ans=max(ans,dp[r]);
	}
	
	printf("%d",ans);
	return 0;
}
