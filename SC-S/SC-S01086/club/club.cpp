#include <bits/stdc++.h>
#define int long long
using namespace std;
int T, n, c1, c2, c3, ans = 0, ma = -1;
struct node {
	int n1, n2, n3;
};
node a[100010];
bool cmp(node x, node y) {
	if (x.n1 != y.n1) {
		return x.n1 > y.n1;
	} else if(x.n2 != y.n2) {
		return x.n2 > y.n2;
	} else {
		return x.n3 > y.n3;
	}
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].n1 >> a[i].n2 >> a[i].n3;
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n / 2; ++i) {
			ans += a[i].n1;
		}
		cout << ans << '\n';
	}
	return 0;
}