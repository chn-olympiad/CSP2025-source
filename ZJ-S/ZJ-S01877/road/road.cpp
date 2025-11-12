#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

long long c[15];
long long a[15][N];

struct nd
{
	int v;
	long long w;
	bool f;
	int x;
};

vector<nd> g[N];

//------------------------------------------

struct Node
{
	int u;
	long long d;
	
	bool operator < (Node x) const
	{
		return x.d < d;
	}
};

long long dis[N];
int vis[N];
int cnt = 0;
long long res = 0;

int n, m, k;

void prim()
{
	priority_queue<Node> pq;
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	
	dis[1] = 0;
	pq.push({1, 0});
	
	while (!pq.empty())
	{
		if (cnt == n)
			break;
		
		Node now = pq.top();
		pq.pop();
		
		int u = now.u;
		long long d = now.d;
		
		if (vis[u])
			continue;
		vis[u] = 1;
		res += d;
		cnt++;
		
		for (auto i: g[u])
		{
			int v = i.v;
			long long w = i.w;
			if (w < dis[v])
			{
				dis[v] = w;
				pq.push({v, w});
			}
		}
	}
}

//------------------------------------------

struct Node2
{
	int u;
	long long d;
	int mask;
	
	bool operator < (Node2 x) const
	{
		return x.d < d;
	}
};

void prim2()
{
	priority_queue<Node2> pq;
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	
	dis[1] = 0;
	pq.push({1, 0, 0});
	
	while (!pq.empty())
	{
		if (cnt == n)
			break;
		
		Node2 now = pq.top();
		pq.pop();
		
		int u = now.u;
		long long d = now.d;
		int mask = now.mask;
		
		if (vis[u])
			continue;
		vis[u] = 1;
		res += d;
		cnt++;
		
		for (auto i: g[u])
		{
			int v = i.v;
			long long w = i.w;
			bool f = i.f;
			int x = i.x;
			
			if (f)
			{
				if (mask & (1 << (x - 1)))
					w -= c[x];
				
				if (w < dis[v])
				{
					dis[v] = w;
					pq.push({v, w, mask | (1 << (x - 1))});
				}
			}
			
			else
			{
				if (w < dis[v])
				{
					dis[v] = w;
					pq.push({v, w, mask});
				}
			}
		}
	}
}

//------------------------------------------

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		long long w;
		cin >> u >> v >> w;
		
		g[u].push_back({v, w, 0, 0});
		g[v].push_back({u, w, 0, 0});
	}
	
	bool f = 0;
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		if (c[i] != 0)
			f = 1;
		
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			
			if (a[i][j] != 0)
				f = 1;
				
			for (int p = j - 1; p >= 1; p--)
			{
				long long w = a[i][j] + a[i][p] + c[i];
				g[j].push_back({p, w, 1, i});
				g[p].push_back({j, w, 1, i});
			}
		}
	}
	
	if (!k)
	{
		prim();
		cout << res;
		
		return 0;
	}
	
	if (!f)
	{
		cout << 0;
		return 0; 
	}
	
	prim2();
	cout << res;
	
	return 0;
}