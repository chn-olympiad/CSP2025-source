#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N = 2e5 + 5;
const ull Mod = 23333333;
int n, q;
string s1[N], s2[N];
ull tmp[N], End[N];
ull a[N], p[N];

ull Get(int l, int r) {
	if (l > r)
		return 0;
	return a[r] - a[l - 1] * p[r - l + 1];
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	p[0] = 1;
	for (int i = 1; i <= 2e5; i++) {
		p[i] = p[i - 1] * Mod;
	}
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		for (int j = 0; j < s1[i].size(); j++) {
			tmp[i] = tmp[i] * Mod + s1[i][j];
		}
		for (int j = 0; j < s2[i].size(); j++) {
			End[i] = End[i] * Mod + s2[i][j];
		}
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << 0 << "\n";
			continue;
		}
		ull res = 0;
		for (int j = 0; j < t2.size(); j++) {
			res = res * Mod + t2[j];
		}
		for (int j = 0; j < t1.size(); j++) {
			a[j + 1] = a[j] * Mod + t1[j];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j + s1[i].size() - 1 <= t2.size(); j++) {
				if (Get(j, j + s1[i].size() - 1) == tmp[i]) {
					ull x = Get(1, j - 1);
					ull z = Get(j + s1[i].size(), t2.size());
					ull tmp = x * p[s1[i].size()] + End[i];
					tmp = tmp * p[t2.size() - (j + s1[i].size()) + 1] + z;
					if (tmp == res) {
						ans++;
						break;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}