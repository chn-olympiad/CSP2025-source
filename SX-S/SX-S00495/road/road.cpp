#include <bits/stdc++.h>
using namespace std;
long long ans = 0;

struct stu {
	long long aa, bb, p;
} a[1000005];
long long b[15], c[15][1000005];

long long cmp(stu x, stu y) {
	return x.p < y.p;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].aa >> a[i].bb >> a[i].p;
	}
	for (int i = 1; i <= k; i++) {
		cin >> b[i];
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n - k - 1; i++) {
		ans += a[i].p;
	}
	cout << ans;
	return 0;
}