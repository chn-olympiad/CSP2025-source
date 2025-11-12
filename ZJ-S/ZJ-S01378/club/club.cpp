#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 1;
int g[N][4], a[N], b[N], c[N];
int getint () {
	char ch = getchar ();
	int num = 0, fs = 1;
	while ( ( ch < '0' || ch > '9' ) && ch != '-' ) ch = getchar ();
	if (ch == '-') fs = -1, ch = getchar ();
	while ( ch >= '0' && ch <= '9' ) num = num * 10 + ch - '0', ch = getchar ();
	return num * fs;
}
signed main () {
	freopen ( "club.in", "r", stdin );
	freopen ( "club.out", "w", stdout );
	int T = getint ();
	while ( T -- ) {
		int n = getint ();
		int a1 = 0, b1 = 0, c1 = 0, sum = 0;
		for ( int i = 1; i <= n; i ++ ) {
			int ans = 0, bns = 0;
			for ( int j = 1; j <= 3; j ++ ) {
				g[i][j] = getint ();
				if ( g[i][j] >= bns ) bns = g[i][j], ans = j; 
			}
			sum += bns;
			if (ans == 1) a[++ a1] = bns - max(g[i][2], g[i][3]);
			else if (ans == 2) b[++ b1] = bns - max(g[i][1], g[i][3]);
			else c[++ c1] = bns - max(g[i][1], g[i][2]);
		}
		sort (a + 1, a + 1 + a1);
		sort (b + 1, b + 1 + b1);
		sort (c + 1, c + 1 + c1);
		int del = 0;
		if ( a1 >= n / 2 )
			for (int i = 1; i <= a1 - n / 2; i ++) del += a[i];
		else if (b1 >= n / 2)
			for (int i = 1; i <= b1 - n / 2; i ++) del += b[i];
		else if (c1 >= n / 2)
			for (int i = 1; i <= c1 - n / 2; i ++) del += c[i];
		printf ("%lld\n", sum - del);
	}
	return 0;
}
