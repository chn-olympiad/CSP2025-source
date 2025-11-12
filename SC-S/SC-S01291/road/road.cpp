#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 10000, M = 100000;

int n, m, k;
ll c[12][N + 5];

struct nd {
	int v;
	ll w;
};

struct Edge {
	int u, v;
	ll w;
	bool operator< (const Edge& oth) const {
		return w < oth.w;
	}
}e[M + 5];

int f[N + 5];

int find(int i)
{
	return (f[i] == i ? i : f[i] = find(f[i]));
}

void merge(int a, int b)
{
	int fa = find(a), fb = find(b);
	f[fa] = fb;
}

vector<nd> G[N + 5];

ll Kruskal()
{
	for(int i = 1; i <= n; i++) f[i] = i;
	int g = n;
	ll res = 0;
	for(int j = 1; j <= m; j++)
	{
		int u = e[j].u, v = e[j].v;
		ll w = e[j].w;
		if(find(u) != find(v))
		{
			merge(u, v);
			
			nd a; a.v = v; a.w = w;
			G[u].push_back(a);
			nd b; b.v = u; b.w = w;
			G[v].push_back(b);
			
			res += w;
			g--;
			if(g == 1)
			{
				return res;
			}
		}
	}
}
long long ma;
void init()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		ll w;
		cin >> u >> v >> w;
		Edge ne;
		ne.u = u; ne.v = v; ne.w = w;
		e[i] = ne;
	}
	sort(e + 1, e + m + 1);
	
	for(int i = 1; i <= k; i++)
		for(int j = 0; j <= n; j++)
		{
			cin >> c[i][j];
			ma = max(ma, c[i][j]);
		}
}

int fa[N + 5];
bool pd[N + 5];
ll cost[N + 5];
void dfs(int u, int lst, ll res)
{
	pd[u] = true;
	fa[u] = lst;
	cost[u] = res;
	for(auto v : G[u]) if(!pd[v.v]) dfs(v.v, u, res + v.w);
}

void solve()
{
	init();
	if(ma == 0 && k != 0)
	{
		cout << "0\n";
		return ;
	}
	ll sum = Kruskal();
	cout << sum << '\n';
	return ;
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int t = 1;
	while(t--)
	{
		solve();
	}
	
	return 0;
} 