#include <bits/stdc++.h>
using namespace std;
int n, m, a[505], s, k;
long long ans = 1;

int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	k = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0)
			k--;
	}
	while (k > 0) {
		ans *= k;
		k--;
	}
	cout << ans % 998244353 ;
	return 0;
}
