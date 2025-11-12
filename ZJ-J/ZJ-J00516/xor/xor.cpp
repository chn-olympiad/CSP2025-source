#include<bits/stdc++.h>
using namespace std;
int vis[500010],k,n,edge[500010],dp[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&vis[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==k){edge[i]=i+1;}
		else
		{
			for(int t=vis[i],j=i+1;j<=n;j++)
			{
				t^=vis[j];
				if(t==k){edge[i]=j+1;break;}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dp[edge[i]]<=dp[i]){dp[edge[i]]=dp[i]+1;}
		if(dp[i+1]<dp[i]){dp[i+1]=dp[i];}
	}
	printf("%d",dp[n+1]);
	return 0;
}
