#include<bits/stdc++.h>
using namespace std;

#define il inline
#define N 100010
#define M 1000010
#define ll long long
const ll INF = 1e16;

bool tes1;

char ch;

template <typename T>
il void read( T &x )
{
	x = 0; ch = getchar();
	for( ; ch < '0' || ch > '9'; ch = getchar() ) ;
	for( ; ch >= '0' && ch <= '9'; ch = getchar() )
		x = x * 10 + ch - '0';
}

template <typename T>
void write( T x )
{
	if( x >= 10 ) write( x / 10 );
	putchar( x % 10 + '0' );
}

int n, m, K, f[N];
ll a[12];
//int val[15][N];
struct node {
	int x, y; ll w;
	bool operator < (const node &z) const {
		return w < z.w;
	}
} e[M], edg[N], val[12][N];

int find( int x )
{
	if( f[x] == x ) return x;
	else return f[x] = find( f[x] );
}

struct sub2 {
	
	node b[M];
	int tot = 0; ll res = INF;
	
	il void krus1()
	{
		for( int i = 1; i <= n; i ++ ) f[i] = i;
		sort( e + 1, e + m + 1 );
		for( int i = 1, x, y; i <= m; i ++ )
		{
			x = find( e[i].x ); y = find( e[i].y );
			if( x == y ) continue;
			f[x] = y; b[++tot] = e[i];
			if( tot == n - 1 ) break;
		}
		for( int i = 1; i <= tot; i ++ ) edg[i] = b[i];
	}
	
	il void calc( int id )
	{
		int nw = 0, i = 1, j = 1;
		while( i <= tot && j <= n )
		{
			if( e[i] < val[id][j] ) b[++nw] = e[i], i ++;
			else b[++nw] = val[id][j], j ++;
		}
		while( i <= tot ) b[++nw] = e[i], i ++;
		while( j <= n ) b[++nw] = val[id][j], j ++;
		for( i = 1; i <= nw; i ++ ) e[i] = b[i];
		tot = nw;
	}
	
	il void krus2( int S )
	{
		for( int i = 1; i <= n + K; i ++ ) f[i] = i;
		for( int i = 1; i <= n - 1; i ++ ) e[i] = edg[i];
		
		int num = n, nw = 0; ll ans = 0; tot = n - 1;
		for( int i = 1; i <= K; i ++ )
			if( (S >> (i - 1)) & 1 )
			{
				ans += a[i]; num ++;
				calc( i );
//				for( int j = 1; j <= n; j ++ )
//					e[++tot] = val[i][j];
//					e[++tot] = {n + i, j, val[i][j]};
			}
//		sort( e + 1, e + tot + 1 );
		
		for( int i = 1, x, y; i <= tot; i ++ )
		{
			if( ans >= res ) return ;
			x = find( e[i].x ); y = find( e[i].y );
			if( x == y ) continue;
			nw ++; ans += e[i].w; f[x] = y;
			if( nw == num - 1 ) break;
		}
		res = min( res, ans );
//		cout << S << " : " << ans << endl;
	}
	
	il void sol()
	{
		krus1();
		for( int S = 0; S < (1 << K); S ++ )
			krus2( S );
		write( res ); puts( "" );
	}
} sub2;

bool tes2;

signed main()
{
//	cout << (&tes1 - &tes2) / 1024 / 1024 << endl;
	freopen( "road.in", "r", stdin );
	freopen( "road.out", "w", stdout );
	read( n ); read( m ); read( K );
	for( int i = 1, x, y, w; i <= m; i ++ )
	{
		read( x ); read( y ); read( w );
		e[i] = {x, y, w};
	}
	for( int i = 1; i <= K; i ++ )
	{
		read( a[i] );
//		for( int j = 1; j <= n; j ++ ) read( val[i][j] );
		for( int j = 1, w; j <= n; j ++ )
		{
			read( w );
			val[i][j] = {n + i, j, w};
		}
		sort( val[i] + 1, val[i] + n + 1 );
	}
//	cout << clock() << endl;
	sub2.sol();
//	cout << clock() << endl;
	return 0;
}
