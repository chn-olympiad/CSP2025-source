#include <bits/stdc++.h>
using namespace std;
int a[500005], dp[500005];

struct qj {
	int l, r;
} b[500005];

bool cmp(qj x, qj y) {
	if (x.l == y.l)
		return x.r < y.r;
	return x.l < y.l;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	long long t = 0;
	for (int i = 1; i <= n; i++) {
		long long x = a[i];
		if (x == k) {
			t++;
			b[t].l = i, b[t].r = i;
		}
		for (int j = i + 1; j <= n; j++) {
			x = x ^(long long)a[j];
			if (x == k) {
				t++;
				b[t].l = i, b[t].r = j;
				break;
			}
		}
	}
	sort(b + 1, b + t + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= t; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (b[j].r < b[i].l)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[t]);
	}
	cout << ans;
	return 0;
}