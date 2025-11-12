#include <bits/stdc++.h>
using namespace std;
long long k, n, a[500005], l, ss, s, r, mid, c[1000005], f, ff[10000005], as, yh, f2;

struct node {
	long long z, y;
} w[1000005];

bool cmp(node a, node b) {
	return a.z < b.z;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0)
			ss++;
		if (a[i] != 1)
			f = 1;
		if (a[i] != 1 && a[i] != 0)
			f = 2;
	}
	if (f == 0) {
		cout << n;
		return 0;
	} else if (f == 1) {
		if (k == 0) {
			cout << ss;
			return 0;
		} else {
			cout << n - ss;
			return 0;
		}
	} else {
		for (int i = 1; i <= n; i++) {
			yh = a[i];
			for (int j = i; j <= n; j++) {
				if (i == j)
					yh = a[i];
				else
					yh = yh ^ a[j];
				if (yh == k) {
					s++;
					w[s].z = i, w[s].y = j;
					break;
				}
			}
		}
		sort(w + 1, w + 1 + s, cmp);
		for (int i = 1; i <= s; i++) {
			f2 = 0;
			for (int j = w[i].z; j <= w[i].y; j++) {
				if (c[j] != 0) {
					f2 = 1;
					break;
				}
				c[j]++;
			}
			if (f2 == 0)
				as++;
		}
	}
	cout << as;
	return 0;
}