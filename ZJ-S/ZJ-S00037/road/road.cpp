#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;

const ll N = 1e4 ;

const ll M = 2e6 ;

const ll K = 10 ;

const ll L = 1024 ;

ll n, m, k, cnt, ans = LONG_LONG_MAX ;

ll val[K + 5] ;

ll w[K + 5][N + 5] ;

struct Edge
{
	ll u, v, w ;
	
	const bool operator < (const Edge other) const
	{
		return w < other.w ;	
	}	
} ;

Edge edge[M + 5] ;

ll fa[N + K + 5] ;

ll sz[N + K + 5] ;

ll Find(ll x)
{
	if(fa[x] == x)
	{
		return x ;
	}
	
	return fa[x] = Find(fa[x]) ;
}

void Union(ll x, ll y)
{
	if(sz[x] > sz[y]) swap(x, y) ;
	fa[Find(x)] = Find(y) ;
}

//void P()
//{
//	sort(edge + 1, edge + 1 + cnt) ;
//	
//	int tot = 0 ;
//	
//	for(ll i = 1 ; i <= cnt ; i ++)
//	{
//		Edge x = edge[i] ;
//		
//		ll u = x.u, v = x.v, w = x.w ;
//		
//		if(Find(u) != Find(v))
//		{
//			edge[++ tot] = x ;
//			Union(u, v) ;
//		}
//	}
//	
//	cnt = tot ;
//}

ll G()
{
	ll ans = 0 ;
	
	sort(edge + 1, edge + 1 + cnt) ;
	
	for(ll i = 1 ; i <= cnt ; i ++)
	{
		Edge x = edge[i] ;
		
		ll u = x.u, v = x.v, w = x.w ;
		
		if(Find(u) != Find(v))
		{
			ans += w ;
			Union(u, v) ;
		}
	}
	
	return ans ;
}

void F(ll state)
{
	ll sum = 0 ;
	
	for(ll i = 1 ; i <= n + k ; i ++)
	{
		fa[i] = i ;
	}
	
	cnt = m ;
	
	for(ll i = 1 ; i <= k ; i ++)
	{
		if((state >> (i - 1)) & 1)
		{
			for(ll j = 1 ; j <= n ; j ++)
			{
				cnt ++ ;
				
				edge[cnt].u = n + i ;
				edge[cnt].v = j ;
				edge[cnt].w = w[i][j] ;
			}
			
			sum += val[i] ;
		}
	}
	
	ans = min(ans, G() + sum) ;
}

void dfs(ll deep, ll state)
{
	if(deep > k)
	{
		F(state) ;
		return ;
	}
	
	dfs(deep + 1, state << 1) ;
	dfs(deep + 1, state << 1 | 1) ;
}

int main()
{
	freopen("road.in", "r", stdin) ;
	freopen("road.out", "w", stdout) ;
	
	cin >> n >> m >> k ;
	
	for(ll i = 1 ; i <= m ; i ++)
	{
		ll u, v, w ;
		cin >> u >> v >> w ;
		
		cnt ++ ;
		edge[cnt].u = u ;
		edge[cnt].v = v ;
		edge[cnt].w = w ;
	}
	
	bool flag = true ;
	
	for(ll i = 1 ; i <= k ; i ++)
	{
		cin >> val[i] ;
		
		if(val[i] != 0)
		{
			flag= false ;
		}
		
		for(ll j = 1 ; j <= n ; j ++)
		{
			cin >> w[i][j] ;
			
			if(w[i][j] != 0)
			{
				flag = false ;
			}
		}
	}
	
	if(flag == true)
	{
		cout << 0 << '\n' ;
		return 0 ;
	}
	
//	P() ;
	
	dfs(1, 0) ;
	
	cout << ans << '\n' ;
	
	return 0 ;
}
