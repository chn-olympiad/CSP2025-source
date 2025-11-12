#include<bits/stdc++.h>
#define int long long
#define PII pair<int, int>

using namespace std;

const int N = 1e4 + 100, M = 1.1e6 + 10;

int n, m, k;

namespace Case1
{
	struct Edge
	{
		int u, v, w;
	}e[M];
	
	int MST = 0;
	int fa[N];
	
	int find(int x)
	{
		if(fa[x] == x)
		{
			return x;
		}
		
		return fa[x] = find(fa[x]);
	}
	
	inline bool cmp(Edge A, Edge B)
	{
		return A.w < B.w;
	}
	
	void Kruskal()
	{
		for(int i = 1; i <= n; i ++)
		{
			fa[i] = i;
		}
		
		sort(e + 1, e + 1 + m, cmp);
		
		for(int i = 1; i <= m; i ++)
		{
			int u = find(e[i].u), v = find(e[i].v);
			
			if(u == v)
			{
				continue;
			}
			
			MST += e[i].w;
			fa[u] = v;
		}
	}
	
	void work()
	{
		for(int i = 1; i <= m; i ++)
		{
			scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
		}
		
		Kruskal();
		
		cout << MST;
		
		return;
	}
}

namespace Case0
{
	int c[20];
	int a[20][N];
	struct Edge
	{
		int u, v, w;
	}e[M];
	
	int MST = 0;
	int fa[N];
	
	int find(int x)
	{
		if(fa[x] == x)
		{
			return x;
		}
		
		return fa[x] = find(fa[x]);
	}
	
	inline bool cmp(Edge A, Edge B)
	{
		return A.w < B.w;
	}
	
	void Kruskal()
	{
		for(int i = 1; i <= n; i ++)
		{
			fa[i] = i;
		}
		
		sort(e + 1, e + 1 + m, cmp);
		
		for(int i = 1; i <= m; i ++)
		{
			int u = find(e[i].u), v = find(e[i].v);
			
			if(u == v)
			{
				continue;
			}
			
			MST += e[i].w;
			fa[u] = v;
		}
	}
	
	void work()
	{
		for(int i = 1; i <= m; i ++)
		{
			scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
		}
		
		for(int i = 1; i <= k; i ++)
		{
			scanf("%lld", &c[i]);
			
			for(int j = 1; j <= n; j ++)
			{
				scanf("%lld", &a[i][j]);
				
				e[++ m] = {n + i, j, a[i][j] + c[i]};
			}
		}
		
		Kruskal();
		
		cout << MST;
		
		return;
	}
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	if(k == 0)
	{
		Case1 :: work();
		return 0;
	}
	else
	{
		Case0 :: work();
		return 0;
	}
	
	return 0;
}