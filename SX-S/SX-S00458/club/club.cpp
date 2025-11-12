#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N], b[N], c[N], v[14], a1[N], b1[N], c1[N];

int main() {
	long long t, n, maxx;
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		maxx = 0;
		memset(v, 0, sizeof(v));
		for (int j = 1; j <= n; j++) {
			cin >> a[j] >> b[j] >> c[j];
		}
		for (int j = 1; j <= n; j++) {
			if (max(a[j], max(b[j], c[j])) == a[j]) {
				a1[j] = a[j] - max(b[j], c[j]);
				b1[j] = 2e4+10;
				c1[j] = 2e4+10;
				v[1]++;
			} else if (max(a[j], max(b[j], c[j])) == b[j]) {
				b1[j] = b[j] - max(a[j], c[j]);
				a1[j] = 2e4+10;
				c1[j] = 2e4+10;
				v[2]++;
			} else if (max(a[j], max(b[j], c[j])) == c[j]) {
				c1[j] = c[j] - max(b[j], a[j]);
				b1[j] = 2e4+10;
				a1[j] = 2e4+10;
				v[3]++;
			}
			maxx = maxx + max(a[j], max(b[j], c[j]));
		}
		if (v[1] > (n / 2)) {
			sort(a1 + 1, a1 + n + 1);
			for (int j = 1; j <= v[1] - (n / 2); j++) {
				maxx = maxx - a1[j];
			}
		} else if (v[2] > (n / 2)) {
			sort(b1 + 1, b1 + n + 1);
			for (int j = 1; j <= v[2] - (n / 2); j++) {
				maxx = maxx - b1[j];
			}
		} else if (v[3] > (n / 2)) {
			sort(c1 + 1, c1 + n + 1);
			for (int j = 1; j <= v[3] - (n / 2); j++) {
				maxx = maxx - c1[j];
			}
		}
		cout << maxx << "\n";
	}
	return 0;
}
