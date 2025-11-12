#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll a[110];
ll ans;
ll ans2, ans3;

int fun(int x, int y) {
	if (x % y == 0) {
		return x / y;
	} else {
		return x / y + 1;
	}
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%lld", &a[i]);
	}
	ans = a[1];
	sort(a + 1, a + 1 + n *m, greater<int>());
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == ans) {
			ans2 = fun(i, n);
			cout << ans2 << " ";
			if (ans2 % 2 == 0) {
				ans3 = (ans2 - 1) * m;
				ans3 = i - ans3;
				ans3 = m - ans3 + 1;
				cout << ans3;
				return 0;
			} else {
				ans3 = (ans2 - 1) * m;
				ans3 = i - ans3;
				cout << ans3;
				return 0;
			}
			return 0;
		}
	}
	return 0;
}
