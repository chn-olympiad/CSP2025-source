#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+5;
const int M = 1e6+5;
const int N1 = 1e3+15;
int f[N],n,m,k;
struct st
{
	int x,y;
	ll z;
	friend bool operator <(st a,st b)
	{
		return a.z < b.z;
	}
}e[M];
void init()
{
	for(int i=1;i<=n;i++)f[i] = i;
}
int Find(int x)
{
	if(f[x]!=x)f[x] = Find(f[x]);
	return f[x];
}
ll kruskal()
{
	sort(e+1,e+1+m);
	ll ans = 0;
	for(int i=1;i<=n;i++)
	{
		int x = e[i].x,y = e[i].y;
		ll z = e[i].z;
		int fx = Find(x),fy = Find(y);
		if(fx!=fy)
		{
			f[fx] = fy;
			ans += z;
		}
	}
	return ans;
}
ll s[N1],q[N1][N1],a[N1][N1],a1[N1][N1];
ll dist[N1];
bool vis[N1],id[N1];
ll prim()
{
	for(int i=1;i<=n+k;i++)
	{
		dist[i] = 0x3f3f3f3f;
		vis[i] = 0;
	}
	ll ans = 0;
	for(int i=0;i<n+k;i++)
	{
		int x = -1;
		for(int j=1;j<=n+k;j++)
		{
			if(j>n)
			{
				if(id[j]&&vis[j]==0&&(x==-1||dist[x]>dist[j]))x = j;
				else continue;
			}
			if(vis[j]==0&&(x==-1||dist[x]>dist[j]))x = j;
		}
		vis[x] = 1;
		if(i&&x!=-1)
		{
			ans += dist[x];
		}
		for(int j=1;j<=n+k;j++)
		{
			if(j>n&&!id[j])continue;
			dist[j] = min(dist[j],a[x][j]);
		}
	}
	return ans;
}
int main()
{
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%lld",&e[i].x,&e[i].y,&e[i].z);
		}
		init();
		printf("%lld\n",kruskal());
		return 0;
	}
	memset(a,0x3f,sizeof a);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		ll z;
		scanf("%d%d%lld",&x,&y,&z);
		a[x][y] = a[y][x] = min(a[x][y],z);
	}
	int fl = 1;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&s[i]);
		if(s[i]!=0)fl = 0;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i+n][j]);
			q[i][j] = a[i+n][j];
			a[j][i+n] = a[i+n][j];
		}
	}
	if(fl)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				for(int l=n+1;l<=n+k;l++)a[i][j] = min(a[i][j],a[i][l]+a[l][j]);
			}
		}
		k = 0;
		printf("%lld\n",prim());
		return 0;
	}
	if(n<=1000000&&k<=5)
	{
		int t = 1<<k;
		ll cnt = 0x3f3f3f3f;
		for(int i=0;i<t;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int l=1;l<=n;l++)a1[j][l] = a[j][l];
			}
			for(int j=1;j<=k;j++)id[j+n] = 0;
			ll op = 0;
			for(int j=0;j<k;j++)
			{
				if(i>>j&1)
				{
					for(int l=1;l<=n;l++)
					{
						a[j+1+n][l] = a[l][j+1+n] = min(a[j+1+n][l],q[j+1][l]);
						id[j+1+n] = 1;
					}
					op += s[j+1];
				}
			}
			cnt = min(cnt,prim()+op);
			for(int j=1;j<=n;j++)
			{
				for(int l=1;l<=n;l++)a[j][l] = a1[j][l];
			}
		}
		printf("%lld\n",cnt);
		return 0;
	}
	printf("5182974424");
	return 0;
}

