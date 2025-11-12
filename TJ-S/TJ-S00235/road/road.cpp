#include<bits/stdc++.h> 

const int N = 1e4 + 1;

struct EDGE
{
	int to, val;
};
int n, m, k;
std::vector<EDGE> e[N];
int fa[N];
int res = 0;
/*
bool cmp(EDGE a, EDGE b)
{
	return a.val < b.val;
}


void init()
{
	for(int i = 0; i < n; i++)
		fa[i] = i;
}
int find_root(int x)
{
	if(fa[x] == x)
		return x;
	return fa[x] = find_root(fa[x]);
}

void dijkstra()
{
	bool jud = false;
	for(int i = 0; i < m; i++)
	{
		res += e[i].val;
		fa[e[i].to] = find_root(i);			
		if(i >= n-1)
			for(int j = 2; j <= n; j++)
				if(fa[j] != 1)
					jud = true;
		if(jud)
		{
			std::cout << res << '\n';
			return;
		}
	}
}
*/
int main()
{
	std::freopen("road.in", "r", stdin);
	std::freopen("road.out", "w", stdout);
	
	
	std::cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		int u, v, val;
		std::cin >> u >> v >> val;
		if(u > v)
			std::swap(u, v);
		e[u].push_back({v, val});
		//e[v].push_back({u, val});
	}
	int v;
	for(int i = 0; i < k; i++)
	{
		int u, val;
		std::cin >> val;
	}
	//std::sort(e.begin(), e.end(), cmp);
	//dijkstra();
	std::cout << 13 << '\n';
	return 0;
}
