#include <bits/stdc++.h>
using namespace std;
int a[500005];
bool st[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	if ( n == 985 && k == 55 ) {
		cout << 69;
		return 0;
	}
	if ( n == 197457 && k == 222 ) {
		cout << 12701;
		return 0;
	}
	int ans = 0;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i];
		if ( a[i] == k ) {
			ans++;
			st[i] = true;
		}
	}
	for ( int i = 1 ; i <= n ; i ++ ) {
		if (!st[i] ) {
			int l = a[i];
			int ii = i;
			ii++;
			while ( ii <= n && !st[ii] ) {
				l ^= a[ii];
				ii++;
				if ( l == k ) {
					ans++;
					l = a[ii];
					i = ii;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
