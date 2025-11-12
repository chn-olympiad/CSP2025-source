#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, a[510], ans = 0, b[510], v[510], v1[510][510];
string s;

void check() {
	int now = 0, s1 = 0;
	for (int i = 0; i < n; i++) {
		int f = 0;
		if (a[b[i]] <= now) {
			f = 1;
		}
		if (s[i]) {
			now = 0;
			s1 += 1;
			if (f)
				s1 -= 1;
		} else {
			now += 1;
		}
	}
	if (s1 >= m) {
		ans += 1;
	}
	return;
}

void dfs(int k) {
	if (k == n - 1) {
		check();
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!v[i] && !v1[k][i]) {
			b[k] = i;
			v[i] = 1;
			v1[k][i] = 1;
			dfs(k + 1);
			v[i] = 0;
			b[k] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	cin >> s;
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		if (!s[i])
			break;
		if (i == n - 1) {
			ans = 1;
			for (int j = 1; j <= n; j++) {
				ans = (ans *j) % 998244353;
			}
			printf("%lld", ans);
			return 0;
		}
	}
	dfs(0);
	printf("%lld", ans);
	return 0;
}
