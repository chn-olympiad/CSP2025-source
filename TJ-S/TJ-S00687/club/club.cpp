#include <bits/stdc++.h>

using namespace std;
long long t,n,dp[100005][5],a[100005][5],maxx;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		maxx=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		
		
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i][2]!=0||a[i][3]!=0)
			{
				flag=0;
			}
		}
		if(flag==1)
		{
			long long d[100005],cnt=0;
			for(int i=1;i<=n;i++)
			{
				d[i]=a[i][1];
			}
			sort(1+d,1+d+n);
			for(int i=n;i>n/2;i--)
			{
				cnt+=d[i];
			}
			cout<<cnt<<endl;
			continue;
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(j==1) dp[i][j]=max(dp[i-1][2],dp[i-1][3])+a[i][j];
				if(j==2) dp[i][j]=max(dp[i-1][1],dp[i-1][3])+a[i][j];
				if(j==3) dp[i][j]=max(dp[i-1][2],dp[i-1][1])+a[i][j];
			}
		}
		for(int i=1;i<=3;i++)
		{
			maxx=max(dp[n][i],maxx);
		}
		cout<<maxx;
	}
	
	return 0;
}
