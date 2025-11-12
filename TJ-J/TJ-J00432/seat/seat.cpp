#include <bits/stdc++.h>
using namespace std;
int n, m, score, a[101], s[11][11];
int main () {
	freopen ( "seat.in", "r", stdin );
	freopen ( "seat.out", "w", stdout );
	scanf ( "%d %d", &n, &m );
	for ( int i = 1; i <= n * m; i++ )
	scanf ( "%d", &a[i] );
	score = a[1];
	sort ( a + 1, a + n * m + 1, greater <int> () );
	int r = 1, c = 1;
	bool dir = true;
	for ( int i = 1; i <= n * m; i++ ) {
		s[r][c] = a[i];
		if ( dir ) {
			if ( r < n ) r++;
			else {
				c++;
				dir = false;
			}
		} else {
			if ( r > 1 ) r--;
			else {
				c++;
				dir = true;
			}
		}
	}
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= m; j++ ) {
			if ( s[i][j] == score ) {
				printf ( "%d %d", j, i );
				return 0;
			}
		}
	}
	return 0;
}
