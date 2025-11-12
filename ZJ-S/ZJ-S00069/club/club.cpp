#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 ;
int n, b[5][N], ans, T;
struct node {
	int d[3];
} a[N];
inline int read( ) {
	int num = 0, f = 1;
	char ch = getchar( );
	for( ; ch < '0' || ch > '9' ; ch = getchar( ) ) if( ch == '-' ) f = -1 ;
	for( ; ch >= '0' && ch <= '9' ; ch = getchar( ) ) num = num * 10 + ch - '0' ;
	return num * f;
}
inline int mx( int x, int y, int z ) {
	int c[3]= { x, y, z };
	int maxn = max( x, max( y, z ) );
	if( maxn == x )return 1;
	if( maxn == y )return 2;
	if( maxn == z )return 3;
	return 0;
}
inline void trade( int x, int p, int q ) {
	int d[b[x][0]+5] = { 0 };
	for(int i=1; i<=b[x][0]; i++) {
		int db = b[x][i];
		d[i] = min( a[db].d[x] - a[db].d[p], a[db].d[x] - a[db].d[q] );
	}
	sort( d + 1, d + b[x][0] + 1 );
	for(int i=1; i<=b[x][0]-n/2; i++) {
		ans -= d[i] ;
	}
}
inline void solve( ) {
	n = read( );
	for(int i=1; i<=n; i++) {
		a[i].d[1] = read( ), a[i].d[2] = read( ), a[i].d[3] = read( );
		int pos = mx( a[i].d[1], a[i].d[2], a[i].d[3] );
		b[pos][ ++b[pos][0] ]=i;
		ans += a[i].d[pos];
	}
	if( b[1][0] * 2 > n ) trade(1,2,3);
	if( b[2][0] * 2 > n ) trade(2,1,3);
	if( b[3][0] * 2 > n ) trade(3,1,2);
	printf( "%d\n", ans );
	return ;
}
int main() {
	freopen( "club.in", "r", stdin );
	freopen( "club.out", "w", stdout );
	scanf( "%d", & T );
	while( T -- ) {
		n = ans = 0;
		memset( b, 0, sizeof b );
		solve( );
	}
	return 0;
}