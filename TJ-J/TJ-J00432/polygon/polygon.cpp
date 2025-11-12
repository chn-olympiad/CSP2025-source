#include <bits/stdc++.h>
using namespace std;
int n, a[5001];
long long num = 0;
int main () {
	freopen ( "polygon.in", "r", stdin );
	freopen ( "polygon.out", "w", stdout );
	scanf ( "%d", &n );
	for ( int i = 1; i <= n; i++ ) scanf ( "%d", &a[i] );
	for ( int i = 1; i < ( 1 << n ); i++ ) {
		int sum = 0, maxn = 0, cnt = 0;
		for ( int j = 0; j < n; j++ ) {
			if ( i >> j & 1 ) {
				sum += a[j+1];
				maxn = max ( maxn, a[j+1] );
				cnt++;
			}
		}
		if ( cnt >= 3 && sum > maxn * 2 ) num = ( num + 1 ) % 998244353;
	}
	printf ( "%lld", num );
	return 0;
}
