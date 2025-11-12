#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 50 , M = 1.1e6 + 50;
int n , m , k , c[N] , fa[N]; bool use[N];
struct Edge{int u , v , w;}e[M];
bool operator < (const Edge &a , const Edge &b){return a.w < b.w;}
int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++)
	{
		int u , v , w;
		cin >> u >> v >> w;
		e[i] = {u , v , w};
	}
	for(int i = 1 ; i <= k ; i++)
	{
		cin >> c[i];
		for(int j = 1 ; j <= n ; j++)
		{
			int w; cin >> w;
			e[++m] = {n + i , j , w};
		}
	}
	sort(e + 1 , e + m + 1);
	ll ans = 1e18L;
	for(int s = 0 ; s < (1 << k) ; s++)
	{
		ll res = 0;
		for(int i = 1 ; i <= k ; i++)
		{
			use[i] = (s >> (i - 1)) & 1;
			if(use[i])res += c[i];
		}
		iota(fa + 1 , fa + n + k + 1 , 1);
		for(int i = 1 ; i <= m ; i++)
		{
			auto [u , v , w] = e[i];
			if(u > n && !use[u - n])continue ;
			u = Find(u) , v = Find(v);
			if(u != v)
			{
				fa[u] = v;
				res += w;
			}
		}
		ans = min(ans , res);
	}
	cout << ans << "\n";
	return 0;
}