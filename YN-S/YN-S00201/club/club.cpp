#include <bits/stdc++.h>
using namespace std;
int t, n, c[1000005], ans, maxx, ok[1005][1005], a;

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int T = 1; T <= t; T++) {
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> c[3 * i - 2] >> c[3 * i - 1] >> c[3 * i];
		}
		while (a <= pow(3, n)) {
			for (int N = 1; N <= n; N++)	{
				if (a > 3 * (N - 1))
					ans += c[3 * (N - 1) + 1 + a % (3 * N)];
				else
					ans += c[3 * (N - 1) + 1];
			}
			if (ans > maxx) {
				maxx = ans;
			}
			ans = 0;
			a++;
		}
		cout << maxx;
	}
	return 0;
}