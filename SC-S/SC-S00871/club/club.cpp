#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, a[N], b[N], c[N], T;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		memset(c, 0, sizeof c);
		int cnta = 0, cntb = 0, cntc = 0, flaga = 1, flagb = 1;
		long long ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			if (b[i] != 0) flaga = 0;
			if (c[i] != 0) flagb = 0;
		}
		if (flaga) {
			sort(a + 1, a + 1 + n, greater());
			for (int i = 1; i <= n / 2; i++)
				ans += a[i];
			cout << ans << endl;
			continue;
		}
		if (flagb) {
			sort(a + 1, a + 1 + n, greater());
			sort(b + 1, b + 1 + n, greater());
			for (int i = 1; i <= n; i++) {
				if (a[i] >= b[i] && cnta < n / 2)
					ans += a[i], cnta++;
				else
					ans += b[i], cntb++;
			}
			cout << ans << endl;
			continue;
		}
		sort(a + 1, a + 1 + n, greater());
		sort(b + 1, b + 1 + n, greater());
		sort(c + 1, c + 1 + n, greater());
		for (int i = 1; i <= n; i++)
			ans += max(a[i], max(b[i], c[i]));
		cout << ans << endl;
	}
	return 0;
}