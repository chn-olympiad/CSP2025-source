#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N], b[N], c[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, res = 0, f = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			if (b[i] != 0 || c[i] != 0)
				f++;
		}
		if (f == 0) {
			sort(a + 1, a + n + 1);
			for (int i = 1; i <= n / 2; i++) {
				res += a[i];
			}
			cout << res;
		}
		for (int i = 1; i <= n; i++) {
			res += max(max(a[i], b[i]), c[i]);
		}
		cout << res;
	}

	return 0;
}
//1