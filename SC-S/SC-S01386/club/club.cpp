#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[2][205][205],f[2][N];
int n;
int a[N][15];

void solve1()
{
	memset(dp,0,sizeof dp);
	int nw=0,ans=0;
	for(int i=1;i<=n;i++,nw^=1)
	{
		for(int j=0;j<=(n/2)&&j<=i;j++)
			for(int k=0;k<=(n/2)&&k<=i-j;k++)
			{
				if(i-j-k>n/2) continue;
				dp[nw][j][k]=0;
				if(j) dp[nw][j][k]=max(dp[nw][j][k],dp[nw^1][j-1][k]+a[i][1]);
				if(k) dp[nw][j][k]=max(dp[nw][j][k],dp[nw^1][j][k-1]+a[i][2]);
				if(j+k!=i) dp[nw][j][k]=max(dp[nw][j][k],dp[nw^1][j][k]+a[i][3]);
				if(i==n) ans=max(ans,dp[nw][j][k]);
			}
	}
	printf("%d\n",ans);
}
void solve()
{
	scanf("%d",&n);
	bool flag1=false,flag2=false;
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]),flag1|=a[i][2],flag2|=a[i][3];
	if(flag1&&flag2) return solve1(),void();
	if(!flag1&&!flag2)
	{
		int ans=0;
		vector<int> vec(n);
		for(int i=1;i<=n;i++) vec[i-1]=a[i][1];
		sort(vec.begin(),vec.end(),less<int>());
		for(int i=1;i<=n/2;i++) ans+=vec[i-1];
		printf("%d\n",ans);
		return ;
	}
	memset(f,0,sizeof f);
	int nw=0,ans=0;
	for(int i=1;i<=n;i++,nw^=1)
		for(int j=0;j<=(n/2)&&j<=i;j++)
		{
			if(i-j>n/2) continue;
			f[nw][j]=0;
			if(j) f[nw][j]=max(f[nw][j],f[nw^1][j-1]+a[i][1]);
			if(i-j) f[nw][j]=max(f[nw][j],f[nw^1][j]+a[i][2]);
			if(i==n) ans=max(ans,f[nw][j]);
		}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;scanf("%d",&T);
	while(T--) solve();
	return 0;
}