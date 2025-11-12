#include <bits/stdc++.h>
using namespace std;

int a[100010] = {0}, b[100010] = {0}, c[100010] = {0}, num = 0, abc[123] = {0};


int da(int n) {
	sort(a, a + num);
	sort(b, b + num);
	sort(c, c + num);
	int d[3 * n] = {0}, q = -1, cut = 0;

	for (int i = 1; i <= n / 2 ; i++) {
		int p = q;
		d[i + p ] = a[n - i];
		q++;
	}
	for (int i = 1; i <= n / 2 ; i++) {
		int p = q;
		d[i + p] = b[n - i];
		q++;
	}
	for (int i = 0; i <= n / 2 ; i++) {
		int p = q;
		d[i + p] = c[n - i];
		q++;
	}
	sort(d, d + 3 * n);
	for (int i = 1; i <= n; i ++) {
		cut += d[3 * n - i];
	}
	return cut;
}

int main () {
	freopen("clud.in", "r", stdin);
	freopen("clud.out", "w", stdout);
	int t, n;
	cin >> t;
	for (int i = 1; i <= t; i ++ ) {
		scanf("%d\n", &n);
		num = 0;
		for (int j = 1; j <= n; j++) {
			scanf("%d ", &a[num]);
			scanf("%d ", &b[num]);
			scanf("%d", &c[num]);
			num++;
			if (j != n) {
				scanf("\n");
			}
		}
		abc[i - 1] = da(n);
	}
	for (int i = 1; i <= 3; i ++) {
		cout << abc[i - 1];
	}
	return 0;
}