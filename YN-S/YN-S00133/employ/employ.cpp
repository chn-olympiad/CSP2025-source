#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, t, c[510], cnt[510], tnc[510];
long long ans, zh[510][510];
string s;
bool flag, b[510][510], bb[510];

void dfs(int d, int num) {
	if (d > n) {
		return;
	}

	if (num >= m) {
		long long sum = 1;

		for (int i = 1; i <= n; i++) {

			if (tnc[i]) {
				sum = (sum * zh[cnt[i]][tnc[i]]) % mod;
			}

		}

		for (int i = 1; i <= n - d - 1; i++) {

			sum = (sum * i) % mod;
		}

		ans = (ans + sum) % mod;
		return;
	}

	for (int i = 1; i <= n; i++) {

		bool cd = 0;

		if (c[i] > num && c[i] > d - num && s[d] == '1') {
			num++;
			cd = 1;
		}

		if (b[d][c[i]] == 0 && bb[i] == 0) {
			b[d][c[i]] = 1;
			bb[i] = 1;
			tnc[c[i]]++;
			dfs(d + 1, num);
			bb[i] = 0;
			tnc[c[i]]--;
			num -= cd;
		}
	}

	for (int i = 1; i <= n; i++) {

		b[d][i] = 0;
	}

	return;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;

	for (int i = 0; i < n; i++) {

		if (s[i] == '1') {
			t++;
		}
	}

	for (int i = 1; i <= n; i++) {

		cin >> c[i];
		cnt[c[i]]++;

		if (c[i] < n) {
			flag = 1;
		}
	}

	if (t < m) {
		cout << 0;
		return 0;
	}

	if (n == m) {
		if (flag) {
			cout << 0;
		} else {
			ans = 1;

			for (int i = 2; i <= n; i++) {

				ans = (ans * i) % mod;
			}

			cout << ans;
		}

		return 0;
	}

	for (int i = 1; i <= n; i++) {

		zh[i][1] = zh[i][i] = 1;

		for (int j = 2; j < i; j++) {

			zh[i][j] = (zh[i][j - 1] + zh[i - 1][j - 1]) % mod;
		}
	}

	dfs(0, 0);
	cout << ans;
	return 0;
}