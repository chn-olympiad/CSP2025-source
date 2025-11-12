#include <bits/stdc++.h>
using namespace std;
int n, a[5005], cnt, g[5005];    // Иёзг
bool vis[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for ( int i = 1 ; i <= n ; i ++ )
		cin >> a[i];

	if ( n == 3 ) {
		for ( int i = 1 ; i <= n ; i ++ ) {
			for ( int j = 1 + i ; j <= n ; j ++) {
				for ( int k = 1 + j ; k <= n ; k ++) {
					if ( a[i] + a[j] + a[k] > (max(a[i], max(a[j], a[k])) * 2))
						cnt ++;
				}
			}
		}
		cout << cnt % 998244353 << "\n";
		return 0;
	}

	return 0;
}