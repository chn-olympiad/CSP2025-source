#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+5, M=1e6+5;
int n, m, k, c[maxn], a[15][maxn], fa[maxn*2], ans=1e18, maxx;
struct edge{
	int u, v, w;
}e[M], ee[M], b[maxn];
inline bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
inline int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];	
		}
	}
	sort(e+1, e+m+1, cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int u=find(e[i].u), v=find(e[i].v);
		if(u==v) continue;
		fa[u]=v;
		cnt++;
		b[cnt]=e[i];
		maxx=max(maxx, e[i].w);
		if(cnt==n-1) break;
	}
	for(int i=0;i<=(1<<k)-1;i++)
	{
		for(int j=1;j<=n-1;j++) ee[j]=b[j];
		int tot=n-1;
		int sum=0, num=0;
		for(int j=1;j<=k;j++)
		{
			if(i>>(j-1)&1)
			{
				sum+=c[j];
				for(int l=1;l<=n;l++)
				{
					if(a[j][l]<=maxx)
						ee[++tot]=(edge){j+n, l, a[j][l]};
				}
				num++;
			}
		}
		sort(ee+1, ee+tot+1, cmp);
		cnt=0;
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<=tot;j++)
		{
			int u=find(ee[j].u), v=find(ee[j].v);
			if(u==v) continue;
			fa[u]=v;
			cnt++;
			sum+=ee[j].w;
			if(cnt==n+num-1) break;
		}
		ans=min(ans, sum);
	}
	cout<<ans;
	return 0;
}
