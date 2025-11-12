#include"bits/stdc++.h"
#define ll long long
using namespace std;

const int N = 1e4 + 10;
const int M = 1e6 + 10;
int n, m, k; ll ans, cnt;
struct Edge
{
	int u, v; ll w;
	friend bool operator < (const Edge &x, const Edge &y) {return x.w < y.w;}
}d[M]; 
int fa[N];

int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
	x = find(fa[x]);
	y = find(fa[y]);
	fa[x] = y;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++)
		cin >> d[i].u >> d[i].v >> d[i].w;
	for (int i = 1; i <= k; i++)
		for (int j = 1, a; j <= n + 1; j++)
			cin >> a;
	sort(d + 1, d + 1 + m);
	for (int i = 1; i <= m; i++)
	{
		int u = d[i].u, v = d[i].v; ll w = d[i].w;
		fa[u] = find(u), fa[v] = find(v);
		if (fa[u] != fa[v])
		{
			merge(u, v);
			cnt++;
			ans += w;
		}
	}
	cout << ans;
	return 0;
}

