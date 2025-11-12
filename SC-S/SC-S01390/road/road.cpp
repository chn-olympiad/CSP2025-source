#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 105 ;
const int K = 15 ;
const int ALL = 1027 ;
const int M = 1e6 + 1e5 + 7 ;
vector< pair< int , int > > dir[N] ;
int n , m , k ;
int c[K] , a[K][N] ;
struct Node {
	int u , v , cnt ;
}edge[M];
int b[N] ;
int sz[N] ;
int last = 0 ;
int get_fa( int u ) {
	if ( b[u] == u )	return u ;
	return b[u] = get_fa( b[u] ) ;
}
void merge( int u , int v ) {
	int fau = get_fa( u ) ;
	int fav = get_fa( v ) ;
	if ( sz[u] > sz[v] ) {
		sz[u] = max( sz[u] , sz[v] + 1 ) ;
		b[fav] = fau ;
	}else {
		sz[v] = max( sz[v] , sz[u] + 1 ) ;
		b[fau] = fav ;
	}
}
bool cmp( Node i , Node j ) {
	return i.cnt < j.cnt ;
}
void solve1() {
	int cnt = 0 ;
	sort ( edge + 1 , edge + 1 + last , cmp ) ;
	for ( int i = 1 ; i <= n + k ; i ++ ) {
		b[i] = i ;
		sz[i] = 1 ;
	}
	for ( int i = 1 ; i <= last ; i ++ ) {
		if ( get_fa( edge[i].u ) != get_fa( edge[i].v ) ) {
			merge( edge[i].u , edge[i].v ) ;
			cnt += edge[i].cnt ;
		}
	}cout << cnt << "\n" ;
}int mi = 0x3f3f3f3f3f3f3f3f ;
int dis[N] ;
bool vis[N];
void solve2( int u ) {
	memset( dis , 0x3f, sizeof( dis ) ) ;
	memset( vis , 0 , sizeof(vis) ) ;
	int sum = 0 ;
	int r = 0 ;
	for ( int i = 0 ; i < k ; i ++ ) {
		if ( ( u & ( 1 << i ) ) != 0 )	sum += c[ i + 1 ] , r ++ ;
	}
	dis[1] = 0 ;
	int cnt = 0 ;
	for ( int i = 1 ; i <= n + r ; i ++ ) {
		int choose = 1 ;
		while ( vis[choose] )	choose ++ ;
		for ( int j = 1 ; j <= n + k ; j ++ ) {
			if ( !vis[j] and dis[j] < dis[choose] )	choose = j ;
		}cnt += dis[choose] ;
		vis[choose] = 1 ;
		for ( int j = 0 ; j < dir[choose].size() ; j ++ ) {
			int v = dir[choose][j].first ;
			int w = dir[choose][j].second ;
			if ( dis[v] > w )	dis[v] = w ;
		}if ( choose <= n ) {
			for ( int j = 0 ; j < k ; j ++ ) {
				if ( ( u & ( 1 << j ) ) != 0 ) {
					dis[ n + j + 1 ] = min( dis[ n + j + 1 ] , a[ j + 1 ][choose] ) ;
				}
			}
		}else {
			for ( int j = 1 ; j <= n ; j ++ ) {
				if ( dis[j] > a[choose - n][j] ) {
					dis[j] = a[choose - n][j] ;
				}
			}
		}
	}mi = min( mi , cnt + sum ) ;
}
signed main() {
    freopen( "road.in" , "r" , stdin ) ;
    freopen( "road.out" , "w" , stdout ) ;
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> n >> m >> k ;
    int u , v , w ;
    for ( int i = 1 ; i <= m ; i ++ ) {
    	cin >> u >> v >> w ;
    	dir[u].push_back( { v , w } ) ;
    	dir[v].push_back( { u , w } ) ;
    	edge[ ++ last ] = { u , v , w } ;
	}
	bool r = 1 ;
	for ( int i = 1 ; i <= k ; i ++ ) {
		cin >> c[i] ;
		int t = ( c[i] == 0 ) ;
		for ( int j = 1 ; j <= n ; j ++ ) {
			cin >> a[i][j] ;
			edge[ ++ last ] = { n + i , j , a[i][j] } ;
			if ( a[i][j] == 0 and t == 1 )	t = 2 ;	
		}if ( t != 2 )	r = 0 ;
	}if (r) {
		solve1() ;
	}else {
		for ( int i = 0 ; i < ( 1 << k ) ; i ++ ) {
			solve2(i) ;
		}cout << mi ;
	}
    return 0 ;
}
