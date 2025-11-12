#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, sum;
int a[N], b[N], c[N];
int w[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(w, 0, sizeof(w));
		int a1 = 0, b1 = 0, c1 = 0, w1 = 0;
		int ask = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[i] >> b[i] >> c[i];
			if (a[i] >= b[i] && a[i] >= b[i]) {
				a1++;
			} else if (b[i] >= a[i] && b[i] >= c[i]) {
				b1++;
			} else if (c[i] >= a[i] && c[i] >= b[i]) {
				c1++;
			}
			//int f = min(a[i],	min(b[i], c[i]));
			int ac = max(a[i], max(b[i], c[i]));
			ask += ac;
		}
		if (a1 <= n / 2 && b1 <= n / 2 && c1 <= n / 2) {
			cout << ask << endl;
		}
		if (a1 > n / 2) {
			for (int j = 1; j <= n; j++) {
				int f1 = max(b[i], c[i]);
				w[a[i] - f1]++;
			}
		}
		if (b1 > n / 2) {
			for (int j = 1; j <= n; j++) {
				int f1 = max(b[i], c[i]);
				w[b[i] - f1]++;
			}
		}
		if (c1 > n / 2) {
			for (int j = 1; j <= n; j++) {
				int f1 = max(b[i], c[i]);
				w[c[i] - f1]++;
			}
		}
		if (a1 > n / 2) {
			w1 = a1;
		} else if (b1 > n / 2) {
			w1 = b1;
		} else if (c1 >= n / 2) {
			w1 = c1;
		}
		for (int j = 0; j <= 9; j++) {
			while (w[j] != 0 && w1 >= n / 2) {
				ask -= j;
				w[j]--;
				w1--;
			}
			if (w1 <= n / 2) {
				break;
			}
		}
		cout << ask << endl;
	}
	return 0;
}