#include <bits/stdc++.h>
using namespace std;
#define il inline
const int ccf = 1e5 + 10;
long long t, n, c1 = 0, c2 = 0, c3 = 0, ans = -114514;
bool v1 = true, v2 = true, v3 = true;

struct club {
	long long h1, h2, h3;
} c[ccf];

il void dp(long long b, long long sum) {
	if (b > n) {
		ans = max(ans, sum);
		return;
	}
	if (c1 < n / 2) {
		c1++;
		sum += c[b].h1;
		dp(b + 1, sum);
		c1--;
		sum -= c[b].h1;
	}
	if (c2 < n / 2) {
		c2++;
		sum += c[b].h2;
		dp(b + 1, sum);
		c2--;
		sum -= c[b].h2;
	}
	if (c3 < n / 2) {
		c3++;
		sum += c[b].h3;
		dp(b + 1, sum);
		c3--;
		sum -= c[b].h3;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(c, 0, sizeof(c));
		c1 = c2 = c3 = ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> c[i].h1 >> c[i].h2 >> c[i].h3;
		dp(1, 0);
		cout << ans << endl;
	}
	return 0;
}