#include <bits/stdc++.h>
using namespace std;
int t, n, a[100001][4], rem[4];
long long dfs ( int idx ) {
	if ( idx > n ) return 0;
	int maxn = -1;
	for ( int i = 1; i <= 3; i++ ) {
		if ( rem[i] == 0 ) continue;
		rem[i]--;
		maxn = max ( ( long long ) maxn, dfs ( idx + 1 ) + a[idx][i] );
		rem[i]++;
	}
	return maxn;
}
int main () {
	freopen ( "club.in", "r", stdin );
	freopen ( "club.out", "w", stdout );
	scanf ( "%d", &t );
	while ( t-- ) {
		scanf ( "%d", &n );
		rem[1] = rem[2] = rem[3] = ( n >> 1 );
		for ( int i = 1; i <= n; i++ ) {
			scanf ( "%d %d %d", &a[i][1], &a[i][2], &a[i][3] );
		}
		printf ( "%lld\n", dfs ( 1 ) );
	}
	return 0;
}
