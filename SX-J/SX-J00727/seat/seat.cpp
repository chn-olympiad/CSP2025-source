#include <bits/stdc++.h>
using namespace std;
long long n, m, I = 0;
long long a[110][110];
long long sc[10010], R, dout, t, ww, yy;

int comp(long long le, long long ri) {
	return le > ri;
}

int fin(long long se) {
	long long l = 1, r = n * m, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (sc[mid] == se)
			return mid;
		else if (sc[mid] > se) {
			l = mid;
		} else
			r = mid;
	}
	return -1;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			I++;
			scanf("%lld", &sc[I]);
		}
	}
	R = sc[1];
	sort(sc + 1, sc + 1 + n *m, comp);
	t = fin(R);
	dout = (t - 1) % (2 * n) + 1;
	if (dout <= n)
		yy = dout;
	else
		yy = 2 * n - dout + 1;
	ww = (t - 1) / n + 1;
	printf("%lld %lld", ww, yy);
	return 0;
}
