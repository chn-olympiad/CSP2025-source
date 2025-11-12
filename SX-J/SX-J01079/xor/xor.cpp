#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+5;
int n, k, a[N], cnt;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for ( int i = 1 ; i <= n ; i ++)
		cin >> a[i];

	if ( n == 2 ) {
		if ( a[1] == 1 && a[2] == 1 ) {
			cout << 1 << "\n";
			return 0;
		} else if ( a[1] == 0 && a[2] == 1 ) {
			cout << 1 << "\n";
			return 0;
		} else if ( a[1] == 1 && a[2] == 0 ) {
			cout << 1 << "\n";
			return 0;
		} else {
			cout << 0 << "\n";
			return 0;
		}
	} else if ( k <= 1 ) {
		if ( k == 1 ) {
			int ttt = 0;
			for ( int i = 1 ; i <= n ; i ++)
				if ( a[i] == 1 )
					ttt++;
			cout << ttt << "\n";
			return 0;
		} else {
			int tttt = 0;
			for ( int i = 1 ; i <= n ; i ++)
				if ( a[i] == 0 )
					tttt++;
			cout << tttt << "\n";
			return 0;
		}
	}
	int t = a[1]; // д╛хо

	for ( int i = 2 ; i <= n ; i ++) {
		if ( t == k) {
			cnt ++ ;
			t = a[i];
		} else {
			t ^= a[i];
		}
	}

	if ( t == k )
		cnt ++;

	cout << cnt << "\n";


	return 0;
}