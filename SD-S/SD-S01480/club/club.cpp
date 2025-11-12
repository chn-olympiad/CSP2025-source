#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[4],ans;
struct Node
{
	int x[4];
}a[100010];
bool cmp(Node x,Node y)
{
	int ans1=0,ans2=0;
	for(int i=1;i<=3;i++)
	{
		for(int j=i+1;j<=3;j++)
		{
			if(i==j)	continue;
			ans1=max(ans1,x.x[i]+y.x[j]);
			ans2=max(ans2,x.x[j]+y.x[i]);
		}
	}
	return ans1>ans2;
}
void solve1()
{
	cnt[1]=cnt[2]=cnt[3]=0;
	m=n/2;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(cnt[j]<m)
			{
				cnt[j]++;
				ans+=a[i].x[j];
				break;
			}
		}
	}
	printf("%d\n",ans);
}
void solve2()
{
	m=n/2;
	vector<vector<int> > f[2];
	f[0].resize(m+2);
	for(int i=0;i<=m+1;i++)	f[0][i].resize(m+2);
	f[1].resize(m+2);
	for(int i=0;i<=m+1;i++)	f[1][i].resize(m+2);
	for(int i=1;i<=n;i++)
	{
		for(int x=0;x<=m&&x<=i-1;x++)
		{
			for(int y=0;y<=m&&y<=i-1;y++)
			{
				if(!(y<=m&&x+y<=i-1&&i-1-x-y>=0&&i-1-x-y<=m))	continue;
				f[(i+1)&1][x+1][y]=max(f[(i+1)&1][x+1][y],f[i&1][x][y]+a[i].x[1]);
				f[(i+1)&1][x][y+1]=max(f[(i+1)&1][x][y+1],f[i&1][x][y]+a[i].x[2]);
				f[(i+1)&1][x][y]=max(f[(i+1)&1][x][y],f[i&1][x][y]+a[i].x[3]);
			}
		}
		f[i&1].clear();
		f[i&1].resize(m+2);
		for(int j=0;j<=m+1;j++)	f[i&1][j].resize(m+2);
	}
	for(int x=0;x<=m&&x<=n;x++)
	{
		for(int y=0;y<=m;y++)
		{
			if(!(y<=m&&x+y<=n&&n-x-y>=0&&n-x-y<=m))	continue;
			ans=max(ans,f[(n+1)&1][x][y]);
		}
	}
	printf("%d\n",ans);
}
void solve()
{
	ans=0;
	bool flag=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			scanf("%d",&a[i].x[j]);
		}
		if(a[i].x[3])	flag=1;
	}
	if(n<=200&&flag)	solve2();
	else 				solve1();
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)	solve();
	return 0;
}
/*
100
2
10 9 8
4 0 0
*/
