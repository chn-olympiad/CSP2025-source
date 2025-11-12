#include<bits/stdc++.h>
#define int long long
#define __FAST_IO__ std::ios::sync_with_stdio(0),std::cin.tie(0)
#define __FILE_IO__ freopen("road.in","r",stdin),freopen("road.out","w",stdout)

#define pii std::pair<int,int> 
#define fi first
#define se second

const int N = 1e5+10;
const int M = 1e6+10;

int tot,t,a[20][N];
int n,m,k; 

struct node
{
	int u,v,w;
};

std::vector<node> e,E;

struct DSU
{
	std::vector<int> fa;
	inline void init(int x)
	{
		fa.resize(x+1);	
		for(int i = 1;i <= x;i++) fa[i] = i;
	} 
	int find(int u)
	{
		if(fa[u] == u) return u;
		return fa[u] = find(fa[u]);
	}
	inline void merge(int x,int y)
	{
		x = find(x), y = find(y);
		if(x == y) return ;
		fa[y] = x;
	}
};

int id = 0;

inline int kruskal(std::vector<node> ee)
{
//	std::cout << (++id) << '\n';
//	for(auto edge : ee)
//	{
//		std::cout << edge.u << ' ' << edge.v << '\n';
//	}
	int res = 0;
	DSU d; d.init(n+k+1);
	std::sort(ee.begin(),ee.end(),[](node x,node y){
		return x.w < y.w;
	});
	for(int i = 0;i < ee.size();i++)
	{
		if(d.find(ee[i].u) == d.find(ee[i].v)) continue;
		d.merge(ee[i].u,ee[i].v);
		res += ee[i].w;
	}
	return res;
}

inline void solve()
{
	std::cin >> n >> m >> k;
	while(m--)
	{
		int u,v,w; std::cin >> u >> v >> w;
		e.push_back({u,v,w});
	}
	
//	std::cout << e.size() << '\n';
	
	int res = 0;
	DSU dd; dd.init(n+1);
	std::sort(e.begin(),e.end(),[](node x,node y){
		return x.w < y.w;
	});
	
	int cct = 0;
	for(int i = 0;i < e.size();i++)
	{
		if(dd.find(e[i].u) == dd.find(e[i].v)) continue;
		dd.merge(e[i].u,e[i].v);
		E.push_back(e[i]);
		cct += e[i].w; 
	}
	
//	std::cout << E.size() << '\n';
//	std::cout << cct << '\n';

	for(int i = 0;i < k;i++)
		for(int j = 0;j <= n;j++)
			std::cin >> a[i][j];
	
	int ans = 1e18;
//	std::cout << ans << '\n';
	
	for(int s = 0;s < (1<<k);s++)
	{
//		std::cout << s << '\n';
		int cst = 0;
		std::vector<node> tmp = E;
		for(int i = 0;i < k;i++)
		{
			if((1<<i)&s)
			{
				for(int j = 1;j <= n;j++)
					tmp.push_back({n+i+1,j,a[i][j]});
				cst += a[i][0];
			}
		}
//		std::cout << tmp.size() << '\n';
//		std::cout << cst << '\n';
//		std::cout << kruskal(tmp) << '\n';
		int ksk = kruskal(tmp);
		ans = std::min(ans,ksk+cst);
	}
	std::cout << ans << '\n';
}

signed main()
{
	__FILE_IO__;
	__FAST_IO__;
//	system("fc road4.out road4.ans"); 

	int T = 1;
	while(T--) solve();
	return 0;
}
