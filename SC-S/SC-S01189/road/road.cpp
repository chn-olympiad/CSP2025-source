#include<bits/stdc++.h>
using namespace std ;
const int N=1e4+30 , K=15 ;
#define ll long long
struct edge {
	ll v , w ;
	edge( ll v , ll w ) : v(v) , w(w) {}
};
struct node {
	ll dis , v ;
	bool operator < ( const node b ) const {
		return dis>b.dis ;
	}
};
ll n , m , k , c[K] ;
vector<edge> Map[N] ;
bool vis[N] , build[K] ;
ll ans=0 , dis[N] , f[N] ;
priority_queue<node> q ; 
void solve() {
	memset(vis,0,sizeof(vis)) ;
	memset(dis,0x3f3f3f3f,sizeof(dis)) ;
	node s ;
	s.dis=0 ;
	s.v=1 ;
	dis[1]=0 ;
	q.push(s) ;
	while ( !q.empty() ) {
		node x=q.top() ;
		q.pop() ;
		ll u=x.v ;
		if ( vis[u] ) continue ;
		vis[u]=1 ;
		for ( int i=0 ; i<Map[u].size() ; i++ ) {
			ll v=Map[u][i].v ;
			if ( vis[v] ) continue ;
			if ( v<=n ) {
				if ( dis[v]>Map[u][i].w ) {
					dis[v]=Map[u][i].w ;
					node now=x ;
					now.v=v ;
					now.dis=Map[u][i].w ;
					q.push(now) ;
					f[v]=u ;
				}
			} else {
				if ( dis[v]>Map[u][i].w+c[v-n] ) {
					dis[v]=Map[u][i].w+c[v-n] ;
					node now=x ;
					now.v=v ;
					now.dis=Map[u][i].w+c[v-n] ;
					q.push(now) ;
				}
			}
		}
//		cout<< u << endl ;
//		for ( int i=1 ; i<=n+k ; i++ ) {
//			cout<< dis[i] << " " ;
//		}
//		cout<< endl ;
//		for ( int i=1 ; i<=n ; i++ ) {
//			cout<< f[i] << " " ;
//		}
//		cout<< endl ;
	}
}
int main() {
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout) ;
	cin>> n >> m >> k ;
	for ( int i=1 ; i<=m ; i++ ) {
		ll u , v , w ;
		cin>> u >> v >> w ;
		Map[u].push_back(edge(v,w)) ;
		Map[v].push_back(edge(u,w)) ;
	}
	for ( int i=1 ; i<=k ; i++ ) {
		cin>> c[i] ;
		for ( int j=1 ; j<=n ; j++ ) {
			ll w ;
			cin>> w ;
			Map[n+i].push_back(edge(j,w)) ;
			Map[j].push_back(edge(n+i,w)) ;
		}
	}
	solve() ;
	for ( int i=1 ; i<=n ; i++ ) {
		ans+=dis[i] ;
	}
	bool is[N] ;
	for ( int i=1 ; i<=n ; i++ ) {
		if ( f[i]>n && !is[f[i]] ) {
			ans+=dis[f[i]] ;
			is[f[i]]=1 ;
		}
	}
	cout<< ans ;
	return 0 ;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
6 8 0
1 3 2
1 4 3
1 6 5
2 3 1
2 4 4
3 6 5
4 5 1
5 6 3
*/
