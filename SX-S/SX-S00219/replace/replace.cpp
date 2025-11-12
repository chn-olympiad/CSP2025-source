#include <bits/stdc++.h>
using namespace std;
string a[200005], b[200005], c, d, c1, c2;
long long n, m, s, ans, aa1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (long long i = 1; i <= m; i++) {
		cin >> c1 >> c2;
		ans = 0;
		aa1 = 0;
		for (long long j = 1; j <= n; j++) {
			if (a[i] == c1) {
				aa1 = j;
			}
		}
		if (aa1) {
			c = a[aa1];
			ans = 1;
			d = c2;
			for (int j = 0; j < a[aa1].size(); j++)
				if (c[j] != d[j])
					ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
