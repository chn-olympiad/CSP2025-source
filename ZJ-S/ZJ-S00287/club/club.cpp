#include <bits/stdc++.h>
#define N 210
#define K 110
#define M 100010
#define ll long long
using namespace std;
int n;
int a[N],b[N],c[N];
bool fg=1;
bool f;
ll ans;
ll dp[2][K][K][K];
inline void Main()
{
	ans=0;
	fg=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]) fg=0;
		if(c[i]) fg=0;
	}
	int x=n/2;
	if(fg)
	{
		sort(a+1,a+1+n,greater<int>());
		for(int i=1;i<=n/2;i++) ans+=a[i];
	}
	else
	{
		memset(dp[0],0xff,sizeof dp[0]);
		dp[0][0][0][0]=0;
		for(int s=1;s<=n;s++,memset(dp[f],0xff,sizeof dp[f]),f^=1)
			for(int i=0;i<=x;i++)
				for(int j=0;j<=x;j++)
					for(int k=0;k<=x;k++)
						if(dp[f][i][j][k]>=0)
							dp[f^1][i+1][j][k]=max(dp[f^1][i+1][j][k],dp[f][i][j][k]+a[s]), dp[f^1][i][j+1][k]=max(dp[f^1][i][j+1][k],dp[f][i][j][k]+b[s]), dp[f^1][i][j][k+1]=max(dp[f^1][i][j][k+1],dp[f][i][j][k]+c[s]);
		for(int i=0;i<=x;i++)
			for(int j=0;j<=x;j++)
				for(int k=0;k<=x;k++)
					ans=max(ans,dp[f][i][j][k]);
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) Main();
	return 0;
}
