#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod1 = 1e9+7;
const int mod2 = 998244353;

struct node {
	string s1, s2;
	int len;
	int hash11, hash12;
	int hash21, hash22;
} t[200005];

int power(int a, int b, int mod) {
	int ans = 1;
	while (b > 0) {
		if (b & 1) {
			ans *= a;
			ans %= mod;
		}
		b >>= 1;
		a *= a;
		a %= mod;
	}
	return ans;
}


int n, q;
string t1, t2;
vector<int> re[20005];
int hashsum11[200005], hashsum12[200005], hashsum21[200005], hashsum22[200005];
int f[1005];

bool check(int i, int j) {
	if (t[j].hash11 == (hashsum11[i + t[j].len - 1] - hashsum11[i - 1]) * power(power(10, i, mod1), mod1 - 2, mod1)) {
		if (t[j].hash12 == (hashsum12[i + t[j].len - 1] - hashsum12[i - 1]) * power(power(10, i, mod2), mod1 - 2, mod2)) {
			if (t[j].hash21 == (hashsum21[i + t[j].len - 1] - hashsum21[i - 1]) *power(power(10, i, mod1), mod1 - 2, mod1)) {
				if (t[j].hash22 == (hashsum22[i + t[j].len - 1] - hashsum22[i - 1]) * power(power(10, i, mod2), mod1 - 2, mod2)) {
					return true;
				}
			}
		}
	}
	return false;
}
int ans = 0;

void dfs(int x) {
	for (int i = x; i < n; i++) {
		if (t1[i] != t2[i]) {
			for (auto j : re[x]) {
				if (f[j] == 0) {
					f[j] = 1;
					dfs(x + t[j].len);
					f[j] = 0;
				}

			}
		}
		if (i == n - 1) {
			ans++;
		}
	}
	return ;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> t[i].s1 >> t[i].s2;
		for (int j = 0; j < t[i].s1.length(); j++) {
			t[i].len = t[i].s1.length();
			t[i].hash11 += t[i].s1[j] * power(10, j, mod1) % mod1;
			t[i].hash12 += t[i].s1[j] * power(10, j, mod2) % mod2;
			t[i].hash11 %= mod1;
			t[i].hash12 %= mod2;

			t[i].hash21 += t[i].s2[j] * power(10, j, mod1) % mod1;
			t[i].hash22 += t[i].s2[j] * power(10, j, mod2) % mod2;
			t[i].hash21 %= mod1;
			t[i].hash22 %= mod2;
		}
	}
	while (q--) {
		cin >> t1 >> t2;
		if (t1.length() != t2.length()) {
			cout << 0;
			continue;
		}
		int m = t1.length();
		for (int i = 0; i < m; i++) {
			hashsum11[i] = hashsum11[i - 1] + t1[i] * power(10, i, mod1) % mod1;
			hashsum12[i] = hashsum12[i - 1] + t1[i] * power(10, i, mod2) % mod2;
			hashsum11[i] %= mod1;
			hashsum12[i] %= mod2;

			hashsum21[i] = hashsum21[i - 1] + t2[i] * power(10, i, mod1) % mod1;
			hashsum22[i] = hashsum22[i - 1] + t2[i] * power(10, i, mod2) % mod2;
			hashsum21[i] %= mod1;
			hashsum22[i] %= mod2;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 1; j <= n; j++) {
				if (m - i >= t[j].len) {
					if (check(i, j)) {
						re[i].push_back(j);
					}
				}
			}
		}
		dfs(1);
		cout << ans << '\n';
		ans = 0;
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/