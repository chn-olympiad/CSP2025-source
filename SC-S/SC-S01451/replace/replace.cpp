#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 10, mod = 1e9 + 87;
const int P = 131;
int H1[N], H2[N], p[N];
int h1[N], h2[N];
char S[N], T[N];
string s[N], t[N];

int query1(int l, int r) {
	return (H1[r] - H1[l - 1] * p[r - l + 1] % mod + mod) % mod;
}

int query2(int l, int r) {
	return (H2[r] - H2[l - 1] * p[r - l + 1] % mod + mod) % mod;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int n, q;
	cin >> n >> q;
	p[0] = 1;
	for (int i = 1; i <= 1e4; i++) {
		p[i] = p[i - 1] * P % mod;
	}
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> t[i];
		for (auto &c : s[i]) {
			h1[i] = (h1[i] * P + (c - 'a' + 1)) % mod;
		}
		for (auto &c : t[i]) {
			h2[i] = (h2[i] * P + (c - 'a' + 1)) % mod;
		}
	}
	while (q--) {
		cin >> (S + 1) >> (T + 1);
		int l1 = strlen(S + 1);
		int l2 = strlen(T + 1);
		if (l1 != l2) {
			cout << "0\n";
			continue;
		}
		for (int i = 1; i <= l1; i++) {
			H1[i] = (H1[i - 1] * P + (S[i] - 'a' + 1)) % mod;
		}
		for (int i = 1; i <= l1; i++) {
			H2[i] = (H2[i - 1] * P + (T[i] - 'a' + 1)) % mod;
		}
		int ans = 0;
		for (int i = 1; i <= l1; i++) {
			for (int j = 1; j <= n; j++) {
				if (i + (int)s[j].size() - 1 <= l1) {
					int k = i + (int)s[j].size() - 1;
					if (query1(1, i - 1) == query2(1, i - 1) && query1(k + 1, l1) == query2(k + 1, l2)) {
						if (h1[j] == query1(i, k) && h2[j] == query2(i, k)) {
//							cout << i << " " << j << " " << k << "\n";
//							return 0;
							ans++;
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}