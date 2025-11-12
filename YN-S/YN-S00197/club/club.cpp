#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int MAXS(int z, int x, int v) {
	int p = max(z, x);
	return max(p, v);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n], b[n], c[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		int maxx = 0, q = 0;
		sort(a, a + n, cmp);
		sort(b, b + n, cmp);
		sort(c, c + n, cmp);
		for (int i = 0; i < n; i++) {
			if (a[i] != 0 && b[i] != 0 && c[i] != 0) {
				maxx += a[i];
				maxx += b[i];
				maxx += c[i];
				q++;
			}
			if (q == n / 2) {
				break;
			} else if (q + 1 == n / 2) {
				maxx += MAXS(a[i + 1], b[i + 1], c[i + 1]);
				break;
			}
		}
		cout << maxx << endl;
	}
	return 0;
}