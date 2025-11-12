#include <bits/stdc++.h>
using namespace std;
int n, k, a[500001], x[500001], p[500001], dp[500001];
int main () {
	memset ( p, -0x7f, sizeof ( p ) );
	freopen ( "xor.in", "r", stdin );
	freopen ( "xor.out", "w", stdout );
	scanf ( "%d %d", &n, &k );
	for ( int i = 1; i <= n; i++ ) scanf ( "%d", &a[i] );
	x[1] = a[1];
	for ( int i = 2; i <= n; i++ ) x[i] = x[i-1] ^ a[i];
	p[0] = 0;
	for ( int i = 1; i <= n; i++ ) {
		int v = k ^ x[i];
		dp[i] = max ( dp[i-1], p[v] + 1 );
		p[x[i]] = max ( p[x[i]], dp[i] );
	}
	printf ( "%d", dp[n] );
	return 0;
}
