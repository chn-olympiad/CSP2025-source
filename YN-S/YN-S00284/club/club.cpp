#include <bits/stdc++.h>
using namespace std;
int a[100050];
int b[100050];
int c[100050];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t, n, o;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		int summ = 0, aa = 0, bb = 0, cc = 0, o;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			o = max(a[i], max(b[i], c[i]));
			if (aa >= n) {
				a[i] = 0;
				o = max(a[i], max(b[i], c[i]));
			}
			if (bb >= n) {
				b[i] = 0;
				o = max(a[i], max(b[i], c[i]));
			}
			if (cc >= n) {
				c[i] = 0;
				o = max(a[i], max(b[i], c[i]));
			}
			if (o == a[i] && aa < n / 2) {
				summ += a[i];
				aa++;
			}
			if (o == b[i] && bb < n / 2) {
				summ += b[i];
				bb++;
			}
			if (o == c[i] && cc < n / 2) {
				summ += c[i];
				cc++;
			}

		}
		cout << summ << '\n';
	}
	return 0;
}