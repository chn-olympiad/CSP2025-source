#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 2e6 + 5;
const int K = 15;
int n,m,k,cnt,head[N],siz[N],fa[N],c[K],a[K][N];
long long ans = 1ll << 62;
struct edge
{
	int u,v,w;
	bool operator < (const edge& b)const
	{
		return w < b.w;
	}
}e[M],e2[M];
int find_fa(int x)
{
	return fa[x] = (x == fa[x] ? x : find_fa(fa[x]));
}
void link(int x,int y)
{
	x = find_fa(x);
	y = find_fa(y);
	if(x == y) return; 
	if(siz[x] < siz[y]) 
	{
		fa[x] = y;
		siz[y] += siz[x];
	}
	else 
	{
		fa[y] = x;
		siz[x] += siz[y];
	}
}
void dfs(int x,long long sum)
{
	if(x == k + 1)
	{
		for(int i = 1;i <= n;i++) fa[i] = i;
		for(int i = 1;i <= n;i++) siz[i] = 1;
		for(int i = 1;i <= cnt;i++) e2[i] = e[i];
		sort(e2 + 1,e2 + cnt + 1);
		bool flag = false;
		for(int i = 1;i <= cnt;i++)
		{
			if(find_fa(e2[i].u) != find_fa(e2[i].v))
			{
				sum += e2[i].w;
				link(e2[i].u,e2[i].v);
			}
			else if(!flag)
			{
				flag = true;
				sum += e2[i].w;
			}
		}
		ans = min(ans,sum);
		return;
	}
	dfs(x + 1,sum);
	for(int i = 1;i <= n;i++)
	{
		e[++cnt].u = i;
		e[cnt].v = x;
		e[cnt].w = a[x][i];
	}
	dfs(x + 1,sum + c[x]);
	cnt -= n;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 1;i <= m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for(int i = 1;i <= k;i++)
	{
		scanf("%d",&c[i]);
		for(int j = 1;j <= n;j++) scanf("%d",&a[i][j]);
	}
	cnt = m;
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
