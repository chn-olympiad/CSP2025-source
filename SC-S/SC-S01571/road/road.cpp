#include<bits/stdc++.h>
using namespace std ;
#define Pa pair<long long , int> 
#define fi first
#define se second
const int N = 1e4 + 10 ;
int n , m , k , c[20][N] ;
vector<Pa> g[N] ;
int minn = 0  ;
bool vis[N] ;
void build(int x )
{
	vis[x] = true ;
	for(int i = 0 ; i < g[x].size() ; i ++)
	{
		int v = g[x][i].se , w = g[x][i].fi ;
		if(!vis[v])
		{
			minn += w ;
			build(v) ;
		}
	}
	return ;
}
int main()
{
	freopen("road.in" , "r" , stdin) ;
	freopen("road.out", "w" , stdout) ;
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i ++)
	{
		int u , v , w ;
		scanf("%d%d%d" , &u ,&v,&w) ;
	//	cin >> u >> v >> w ;
		g[u].push_back(make_pair( w,v)) ;
		g[v].push_back(make_pair( w,u)) ;
	}
	for(int i = 1 ; i <= k ; i ++)
	{
		for(int j = 0 ; j <= n  ; j ++)
		{
			//cin >> c[i][j] ;
			scanf("%d" , &c[i][j]) ;
		}
		for(int j = 1 ; j <= n ; j ++)
		{
			for(int k = j + 1 ; k <= n ; k ++)
			{
				g[j].push_back(make_pair(c[i][j ] + c[i][k] + c[i][0], k  )) ;
				g[k].push_back(make_pair(c[i][j ] + c[i][k] + c[i][0] , j)) ;
			}
		}
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		sort(g[i].begin() , g[i].end()) ;
	//	for(int j = 0 ; j < g[i].size() ; j ++) cout << g[i][j].se << ' ' << g[i][j].fi << endl ;
	}
	memset(vis , false , sizeof(vis)) ; 
	build(1) ;
	cout << minn ;
	return 0 ;
}