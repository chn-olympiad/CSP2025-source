#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4];
int dp[205][205][205],p[N];
bool cmp(int a,int b){return a>b;}
void solve1()
{
	for(int i=1;i<=n;++i) p[i]=a[i][1];
	sort(p+1,p+n+1,cmp);
	int ans=0;
	for(int i=1;i<=(n>>1);++i) ans+=p[i];
	printf("%d\n",ans);
}
void solve2()
{
	int ans=0;
	for(int i=1;i<=n;++i) ans+=a[i][1],p[i]=a[i][2]-a[i][1];
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=(n>>1);++i) ans+=p[i];
	printf("%d\n",ans);
}
void solve3()
{
	int o=n>>1,ans=0;
	memset(dp,0,sizeof(dp));
	for(int k=1;k<=n;++k)
		for(int i=0;i<=k&&i<=o;++i)
			for(int j=0;i+j<=k&&j<=o;++j)
			{
				if(k-i-j>o) continue;
				if(i) dp[k][i][j]=max(dp[k][i][j],dp[k-1][i-1][j]+a[k][1]);
				if(j) dp[k][i][j]=max(dp[k][i][j],dp[k-1][i][j-1]+a[k][2]);
				if(k-1>=i+j) dp[k][i][j]=max(dp[k][i][j],dp[k-1][i][j]+a[k][3]);
				ans=max(ans,dp[k][i][j]);
			}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club1.in","r",stdin);
//	freopen("club1.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		bool fg1=1,fg2=1;
		for(int i=1;i<=n;fg1=fg1&&(a[i][2]==0&&a[i][3]==0),fg2=fg2&&(a[i][3]==0),++i) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		if(fg1) solve1();
		else if(fg2) solve2();
		else if(n<=200) solve3();
	}
	return 0;
}
