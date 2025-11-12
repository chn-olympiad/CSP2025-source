#include<bits/stdc++.h> 
using namespace std ;
#define q_q return 0

const int N = 1e5 + 10 ;

struct NODE
{
	int u, v ;
	long long w ;
	bool operator<( const NODE& b ) const
	{
		return w > b.w ;
	}
} ;

priority_queue<NODE> q ;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que ;

vector<NODE> e[N] ;

int n, m, k ;
long long ans ;

long long c[N] ;
int f[N] ;

bool v[N] ;
long long dis[N] ;

int get( int st )
{
	return f[st] == st ? st : f[st] = get( f[st] ) ;
}

long long check( int state )
{
	long long ret = 0 ;
	for(int i=1; i<=k; i++)	if( ( state >> ( i - 1 ) ) & 1 )	que.push( { c[i], n + i } ) ;
	while( !que.empty() )
	{
		auto head = que.top() ;	que.pop() ;
		if( v[head.second] )	continue ;
		v[head.second] = true ;
		ret += head.first ;
		for( auto x : e[head.second] )
		{
			if( v[x.v] || dis[x.v] <= x.w )	continue ;
			dis[x.v] = x.w ;
			que.push( { x.w, x.v } ) ;
		}
	}
	for(int i=1; i<=n+k; i++)	v[i] = false, dis[i] = 1000000000000000ll ;
	return ret ;
}

signed main()
{
	freopen( "road.in", "r", stdin ) ;
	freopen( "road.out", "w", stdout ) ;
	
	ios_base::sync_with_stdio( false ) ;
	cin.tie( nullptr ) ;	cout.tie( nullptr ) ;
	
	memset( dis, 0x3f, sizeof( dis ) ) ;
	
	cin >> n >> m >> k ;
	
	for(int i=1; i<=m; i++)
	{
		NODE r ;	cin >> r.u >> r.v >> r.w ;
		q.push( r ) ;
	}
	
	for(int i=1; i<=n; i++)	f[i] = i ;
	
	while( !q.empty() )
	{
		NODE head = q.top() ;	q.pop() ;
		if( get( head.u ) == get( head.v ) )	continue ;
		e[head.u].push_back( { head.u, head.v, head.w } ) ;
		e[head.v].push_back( { head.v, head.u, head.w } ) ;
		f[get( head.u )] = get( head.v ) ;
		ans += head.w ;
	}
	
	for(int i=1; i<=k; i++)
	{
		cin >> c[i] ;
		for(int j=1; j<=n; j++)
		{
			long long w ;	cin >> w ;
			e[n+i].push_back( { n + i, j, w } ) ;
		}
	}
	
	for(int i=1; i<(1<<k); i++)	ans = min( ans, check( i ) ) ;
	
	cout << ans<< endl ;
	
	q_q ;
}
//	oldmoon:(
//	  |    |---|
//	--|--  |   |
//	  |    |---|
//	|---|  |   |
//	|   |  |---|
//	|---| /    |