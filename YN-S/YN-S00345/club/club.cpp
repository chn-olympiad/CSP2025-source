#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 2, maxc = 4e4 + 2;
int t, num = 0;
long long n;
int a[maxn], b[maxn], c[maxn], d[maxc];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> n;
		int d = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		sort(c + 1, c + n + 1);
		if (b[n] == 0 && c[n] == 0) {
			for (int i = n; i > n / 2; i--)
				ans += a[i];
		} else if (c[n] == 0) {
			for (int i = n; i > n / 2; i--)
				ans += a[i] + b[i];
		} else
			ans = n * a[1];
		cout << ans << endl;
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}