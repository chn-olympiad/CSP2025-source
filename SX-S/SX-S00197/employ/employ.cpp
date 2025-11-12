#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m, g, c[505], jc[505], ans;
string s;

int dfs(int w, int x) {
	if (w > n) {
		if (x < m)
			return 0;
		return 1;
	}
	int sum = 0;
	if (s[w] == '1') {
		for (int i = 0; i <= w - 1 - x; i++) {
			if (c[i] > 0) {
				c[i]--;
				sum += dfs(w + 1, x) * (c[i] + 1);
				c[i]++;
			}
		}
		for (int i = w - x; i <= n; i++) {
			if (c[i] > 0) {
				c[i]--;
				sum += dfs(w + 1, x + 1) * (c[i] + 1);
				c[i]++;
			}
		}
	} else {
		for (int i = 0; i <= n; i++) {
			if (c[i] > 0) {
				c[i]--;
				sum += dfs(w + 1, x) * (c[i] + 1);
				c[i]++;
			}
		}
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	jc[0] = 1;
	for (int i = 1; i <= n; i++)
		jc[i] = 1LL * jc[i - 1] * i % p;
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++)
		if (s[i] == '1')
			g++;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}
	cout << dfs(1, 0);
	return 0;
}
