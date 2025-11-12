#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn], c[maxn];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;

	for (int p = 1; p <= t; p++) {

		int n, cnt = 0;
		cin >> n;

		for (int i = 1; i <= n; i++) {

			cin >> a[i] >> b[i] >> c[i];
		}

		if (n == 2) {
			cout << max(a[1], max(b[1], c[1])) + max(a[2], max(b[2], c[2])) << endl;
			return 0;
		} else {
			sort(b + 1, b + n + 1);

			for (int i = n; i > n / 2; i--)

				cnt += b[i];
			cout << cnt << endl;
		}
	}

	return 0;
}