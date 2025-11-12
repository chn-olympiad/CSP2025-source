#include <bits/stdc++.h>
using namespace std;
int n, a[1000005], c[100005], s, f[1000005], top, man = -1, p[1000005], v[1000005];

void dfs(int k) {
	int su = 0, ma = -1;
	for (int i = 1; i <= k; i++) {
		ma = max(ma, c[i]);
		su += c[i];
	}

	if (2 * ma < su && k >= 3 && ma != -1) {
		p[s] = 1, v[s] = 0;
		for (int i = 1; i <= k; i++) {
			p[s] = (p[s] * c[i]) % 19491001;
			v[s] += c[i];
		}
		s++;
		return;
	}
	if (k == n + 1)
		return;
	for (int i = 1; i <= n; i++) {
		if (f[i] == 0) {
			c[k] = a[i];
			f[i] = 1;
			dfs(k + 1);
			c[k] = 0;
			f[i] = 0;
		}
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n < 3) {
		cout << 0;
	} else if (n == 3) {
		cin >> a[1] >> a[2] >> a[3];
		man = max(a[1], max(a[2], a[3]));
		if (2 * man < a[1] + a[2] + a[3])
			cout << 1;
		else
			cout << 0;
	} else {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dfs(1);
		for (int i = 1; i <= s; i++) {
			for (int j = i; j <= s; j++) {
				if (v[i] == v[j] && p[i] == p[j])
					s--;
			}
		}
		cout << s;
	}
	return 0;
}