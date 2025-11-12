#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],c[100005],d[100005],dp[205][105][105][105];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	if(n>10000)
	{
		if(b[1]==0)
		{
			int ans=0;
			sort(a+1,a+1+n,greater<int>());
			for(int i=1;i<=n/2;i++)
			ans+=a[i];
			cout<<ans<<endl;
		}
		else
		if(c[1]==0)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
			d[i]=a[i]-b[i];
			ans+=a[i];
			}
			sort(d+1,d+1+n,greater<int>());
			for(int i=1;i<=n/2;i++)
			ans-=d[i];
			cout<<ans<<endl;
		}
		continue;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	for(int j=0;j<=n/2;j++)
	for(int k=0;k<=n/2;k++)
	for(int h=0;h<=n/2&&j+k+h<=i;h++)
	if(j+k+h!=i)
	continue;
	else
	{
		if(h!=0)
		dp[i][j][k][h]=max(dp[i-1][j][k][h-1]+c[i],dp[i][j][k][h]);
		if(j!=0)
		dp[i][j][k][h]=max(dp[i-1][j-1][k][h]+a[i],dp[i][j][k][h]);
		if(k!=0)
		dp[i][j][k][h]=max(dp[i-1][j][k-1][h]+b[i],dp[i][j][k][h]);
		if(n-j-k<=n/2&&i==n)
		ans=max(ans,dp[i][j][k][h]);
	}
	cout<<ans<<endl;
	}
	return 0;
}

