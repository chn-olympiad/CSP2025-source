#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005], b[100005], c[100005], mmax;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + n + 1, cmp);
		sort(c + 1, c + n + 1, cmp);
		for (int i = 1; i <= n / 2; i++) {
			mmax = max(a[i], max(b[i], c[i]));
			if (mmax == a[i]) {
				sum += a[i];
			}
			if (mmax == b[i]) {
				sum += b[i];
			}
			if (mmax == c[i]) {
				sum += c[i];
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
