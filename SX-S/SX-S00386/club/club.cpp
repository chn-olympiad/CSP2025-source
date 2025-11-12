#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N=225,M=1e5+10;
int n,a[M][3],dp[N][N][N],ans,t,b[N];
void solve()
{
	ans=0;
	cin>>n;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(a[i][2]!=0||a[i][3]!=0)
			{
				flag=1;
				break;
			}
			if(i==n)
			{
				for(int i=1;i<=n;i++) 
				{
					b[i]=a[i][1];
				}
				sort(b+1,b+1+n);
				for(int i=n;i>n/2;i--) 
				{
					ans+=b[i];
				}
				cout<<ans<<'\n';
				return ;
			}
		}
		if(flag) break;
	}
	for(int i=0;i<=n/2;i++)
	{
		for(int j=0;j<=n/2;j++)
		{
			for(int k=0;k<=n/2;k++)
			{
				if(i+j+k>n) continue;
				int once=0;
				if(i) once=max(once,dp[i-1][j][k]+a[i+j+k][1]);
				if(j) once=max(once,dp[i][j-1][k]+a[i+j+k][2]);
				if(k) once=max(once,dp[i][j][k-1]+a[i+j+k][3]);
				dp[i][j][k]=once;
				ans=max(ans,dp[i][j][k]);
			}
		}
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
