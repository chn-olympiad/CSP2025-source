#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long read()
{
	long long x = 0,f = 1;
	char c = getchar();
	for(;!isdigit(c);)
	{
		if(c == '-') f = -1;
		c = getchar();
	}
	for(;isdigit(c);)
	{
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

int n,m,k;

struct edge
{
	long long u,v,w;
	bool operator <(edge b)
	{
		return w < b.w;
	}
}e[1200005];

bool vis[15];
int c[15];

long long ans = 9e18;

int f[10025];

int find(int x)
{
	return (f[x] == x ? x : f[x] = find(f[x]));
}

void merge(int x,int y)
{
	f[find(x)] = find(y);
}

long long kruskal(int need)
{
//	cout << need << endl;
	long long ret = 0;
	int cnt = 0;
	for(int i = 1;i <= m;i++)
	{
		int u = e[i].u;
		int v = e[i].v;
		int w = e[i].w;
//		cout << u << " " << v << " " << w << endl;
		if(find(u) == find(v)) continue;
		if((u > n && !vis[u - n]) || (v > n && !vis[v - n])) continue;
//		cout << "check" << endl;
		merge(u,v);
		cnt++;
		ret += w;
	}
	if(cnt < need) return -1;
	return ret;
}

void dfs(int step,long long sum,int cnt)
{
	if(step == k + 1)
	{
		for(int i = 0;i <= n + k;i++)
		{
			f[i] = i;
		}
		long long res = kruskal(n - 1 + cnt);
		if(res == -1) return;
		ans = min(ans,res + sum);
		return;
	}
	vis[step] = 1;
	dfs(step + 1,sum + c[step],cnt + 1);
	vis[step] = 0;
	dfs(step + 1,sum,cnt);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].w = read(); 
	}
	for(int i = 1;i <= k;i++)
	{
		c[i] = read();
		for(int j = 1;j <= n;j++)
		{
			int w;
			w = read();
			e[++m] = {n + i,j,w};
		}
	}
	sort(e + 1,e + m + 1);
	dfs(1,0,0);
	cout << ans << endl;
	return 0;
}
