#include <bits/stdc++.h>
using namespace std;
int a[5010];
long long maxx1 = LLONG_MIN, n;

void xz(long long ans, int i, int s, int maxx, int gs) {
	if (s > maxx * 2) {
		maxx1 = max(maxx1, ans);
	}
	if (i > n) {
		return;
	}
	for (int j = 1; j <= 2; j++) {
		if (j == 1) {
			int z;
			z = maxx;
			maxx = max(maxx, a[i]);
			xz(ans + 1, i + 1, s + a[i], maxx, gs + 1);
			maxx = z;
		} else {
			xz(ans, i + 1, s, maxx, gs);
		}
	}
}

int main() {
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	long long s = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s = s + a[i];
		maxx1 = max(maxx1, 1ll * a[i]);
	}
	int f;
	if (s > maxx1 * 2)
		f = 1;
	else
		f = 0;
	maxx1 = -1;
	xz(0, 1, 0, -1, 0);
	if (f == 1)
		cout << (maxx1 + 1) % 998244353;
	else
		cout << maxx1 % 998244353;
	return 0;
}
