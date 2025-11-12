#include <bits/stdc++.h>
using namespace std;
int a[5005];
int n;
long long ans = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for ( int i = 1 ; i <= n ; i ++ ) {
		for ( int j = i + 1 ; j <= n ; j ++ ) {
			for ( int k = j + 1 ; k <= n ; k ++ ) {
				if ( a[i] + a[j] + a[k] > a[k] * 2 )
					ans++;
				for ( int l = k + 1 ; l <= n ; l ++ ) {
					if ( a[i] + a[j] + a[k] + a[l] > a[l] * 2 )
						ans++;
					for ( int h = l + 1 ; h <= n ; h ++ ) {
						if ( a[i] + a[j] + a[k] + a[l] + a[h] > a[h] * 2 )
							ans++;
						for ( int g = h + 1 ; g <= n ; g ++ ) {
							if ( a[i] + a[j] + a[k] + a[l] + a[h] + a[g] > a[g] * 2 )
								ans++;
						}
					}
				}
			}
			ans %= 998244353;
		}
	}
	cout << ans;
	return 0;
}
