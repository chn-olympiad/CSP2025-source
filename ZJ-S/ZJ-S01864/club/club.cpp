#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5 ;
int T;
int n;
int a[maxn][5],c[maxn];
long long dp[1005][1005][5];
void cal1()
{
	for(int i=1;i<=n;i++)	c[i]=a[i][1];
	sort(c+1,c+1+n);
	long long res=0;
	for(int i=n;i>n/2;i--)	res+=c[i];
	cout<<res<<'\n';
}
long long cal(int h,int m,int d)
{
	long long res=0;
	for(int i=1;i<=m;i++)	res=max(res,dp[h][i][d]);
	return res;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int flag=1;
		for(int i=1;i<=n;i++)	cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++)
			if(a[i][2]!=0||a[i][3]!=0)
			{
				flag=0;
				break ;
			}
		if(flag==1)
		{
			cal1();
			continue ;
		}
		else
		{
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=min(n/2,i);j++)	
				{
					dp[i][j][1]=max(dp[i-1][j-1][1],max(cal(i-1,j,2),cal(i-1,j,3)))+a[i][1];
					dp[i][j][2]=max(dp[i-1][j-1][2],max(cal(i-1,j,1),cal(i-1,j,3)))+a[i][2];
					dp[i][j][3]=max(dp[i-1][j-1][3],max(cal(i-1,j,1),cal(i-1,j,2)))+a[i][3];
//				cout<<dp[i][j][2]<<' '<<i<<' '<<j<<'\n';
				}
			}	
			long long ans=0;
			for(int i=1;i<=n/2;i++)
			{
				ans=max(ans,dp[n][i][1]);
				ans=max(ans,dp[n][i][2]);
				ans=max(ans,dp[n][i][3]);
			}
			cout<<ans<<'\n';
		}	
	}
	return 0;	
}
