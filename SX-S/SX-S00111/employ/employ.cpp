#include <bits/stdc++.h>
using namespace std;
int n, m, s[1001], c[1001], g = 0;
bool f[1001];
long long ans = 1;
string ss;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> ss;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		if (c[i] == 0)
			g++;
	}
	sort(c + 1, c + 1 + n);
	for (int i = 1; i <= n; i++) {
		cout << c[i] << " " << i << "\n";
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) {
			g++;
			f[i] = 1;
		}
	}
	bool flag = 1;
	while (flag == 1) {
		flag = 0;
		for (int i = 1; i <= n; i++) {
			if (g >= c[i] && f[i] == 0) {
				g++;
				f[i] = 1;
				flag = 1;
			}
		}
	}
	cout << g;
	for (int i = 2; i <= n - g; i++) {
		ans = ((ans % 998244353) * i) % 998244353;
	}
	printf("%lld\n", ans);
	return 0;
}
