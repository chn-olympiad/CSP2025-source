#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+10, M=1e6+10, K=12, INF=1e18;

int read()
{
	char ch=' ';
	while(ch>'9' || ch<'0')
		ch = getchar();
	int x = ch-'0';
	ch = getchar();
	while(ch<='9' && ch>='0')
	{
		x = (x<<3) + (x<<1) + (ch-'0');
		ch = getchar();
	}
	return x;
}

struct Edge { int u, v, w; };

int n, m, k, ans=INF;
int c[K];
Edge E1[M], E[N+N*K];
int cte;

int fa[N+K], sz[N+K];
int find(int x) { return (x==fa[x]) ? x : (fa[x] = find(fa[x])); }
void Union(int u, int v)
{
	if(sz[u] < sz[v]) swap(u, v);
	fa[v] = u; sz[u] += sz[v];
}

void Union1(int u, int v) { fa[u] = v; }

void Union2(int u, int v)
{
	if(sz[u] > sz[v]) swap(u, v);
	fa[v] = u; sz[u] += sz[v];
}

int cnt;

void Kruskal1()
{
	for(int i=1; i<=n; i++)
		fa[i] = i, sz[i] = 1;
	for(int i=1; i<=m&&cnt<n-1; i++)
	{
		int fu = find(E1[i].u), fv = find(E1[i].v);
		if(fu == fv)
			continue;
		Union(fu, fv);
		E[++cnt] = {E1[i].u, E1[i].v, E1[i].w};
	}
}

int f[K], cntn;

int Kruskal()
{
	cntn = n; int res = 0;
	for(int i=1; i<=k; i++)
		cntn += f[i], res += f[i] * c[i];
	for(int i=1; i<=n+k; i++)
		fa[i] = i, sz[i] = 1;
	//cout << res << '\n';
	int ct=0;
	for(int i=1; i<=cnt&&ct<cntn-1; i++)
	{
		int fu = find(E[i].u), fv = find(E[i].v);
		if((fu>n&&!f[fu-n]) || fu==fv) continue;
		Union(fu, fv);
		ct ++; res += E[i].w;
	}
	return res;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);
	n = read(); m = read(); k = read();
	for(int i=1; i<=m; i++)
	{
		E1[i].u = read(); E1[i].v = read(); E1[i].w = read();
	}
	sort(E1+1, E1+m+1, [&](Edge x, Edge y){return x.w<y.w;});
	Kruskal1();
	for(int i=n+1; i<=n+k; i++)
	{
		c[i-n] = read();
		for(int j=1; j<=n; j++)
		{
			cnt ++;
			E[cnt].u = i; E[cnt].v = j;
			E[cnt].w = read();
		} 
	}
	sort(E+1, E+cnt+1, [&](Edge x, Edge y){return x.w<y.w;});
	for(int i=0; i<(1<<k); i++)
	{
		for(int j=1; j<=k; j++)
			f[j] = (i&(1<<(j-1))) ? 1 : 0;
		int x = Kruskal();
		ans = min(ans, x);
	}
	cout << ans;
    return 0;
}

