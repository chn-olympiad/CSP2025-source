#include <bits/stdc++.h>
using namespace std;
int t, n, m, s, p;
int a[100010], b[100010], c[100010];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		s = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			cin >> b[i];
			cin >> c[i];
		}
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		sort(c + 1, c + n + 1);
		for (int i = 1; i <= 3; i++) {
			s = 0;
			for (int j = n; j >= n / 2; j--) {
				if (i = 1)
					s += a[j];
				if (i = 2)
					s += b[j];
				if (i = 3)
					s += c[j];
			}
			p = max(s, p);
		}
		cout << p + a[n] + c[n];
	}
	return 0;
}