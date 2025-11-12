#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	double n, m;
	scanf( "%lf %lf", &n, &m );
	int sum = n * m;

	int a1, ai;
	int pai = 1;
	int r;

	scanf( "%lld ", &a1 );

	for ( int i = 1; i < sum; i ++ ) {
		scanf( "%lld", &ai );
		if ( ai > a1 )
			pai ++ ;
	}

	int c = ceil( pai / n );

	if ( c % 2 ) {
		if ( pai % (int)n == 0 ) {
			r = n;
		} else {
			r = pai % (int)n;
		}

	} else {
		r = n - pai % (int)n + 1;
	}

	printf("%lld %lld", c, r);

	return 0;
}
