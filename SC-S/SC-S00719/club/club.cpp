#include<bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int a[100001],b[100001],c[100001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)
	{
		int n,maxx=-2e9-5;
		cin>>n;bool flag=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]>0 || c[i]>0) flag=0;
		}
		if(flag)
		{
			sort(a+1,a+n+1);
			int ans=0;
			for(int i=n;i>n/2;i--) ans+=a[i];
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=n/2;j>=0;j--)
				for(int k=n/2;k>=0;k--)
				{
					if(i-j-k<=n/2) dp[j][k]=max(dp[j][k],dp[j][k]+c[i]);
					if(j>0) dp[j][k]=max(dp[j][k],dp[j-1][k]+a[i]);
					if(k>0) dp[j][k]=max(dp[j][k],dp[j][k-1]+b[i]);
					if(i==n) maxx=max(maxx,dp[j][k]);
				}
		}
		cout<<maxx<<endl;
		for(int j=0;j<=n/2+1;j++)
			for(int k=0;k<=n/2+1;k++) dp[j][k]=0;
	}
	return 0;
}