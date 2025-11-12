#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<uLL, uLL> puu;
#define F first
#define S second
#define mk_p make_pair

constexpr int N = 1e5 + 5;
constexpr uLL base1 = 23333, base2 = 37777;

int n, T;
int siz[N];
string s1[N], s2[N], s, t;
puu hsh1[N], hsh2[N], h1[N], h2[N], pw[N];

puu get_hash1(int l, int r) {
	if (!l)
		return h1[r];
	return mk_p(h1[r].F - h1[l - 1].F *pw[r - l + 1].F, h1[r].S - h1[l - 1].S *pw[r - l + 1].S);
}

puu get_hash2(int l, int r) {
	if (!l)
		return h2[r];
	return mk_p(h2[r].F - h2[l - 1].F *pw[r - l + 1].F, h2[r].S - h2[l - 1].S *pw[r - l + 1].S);
}

void _main() {
	cin >> s >> t;
	if (s.size() != t.size()) {
		cout << 0 << '\n';
		return;
	}
	int len = s.size();
	for (int i = 0; i < len; i++) {
		h1[i] = mk_p(h1[i - 1].F *base1 + s[i], h1[i - 1].S *base2 + s[i]);
		h2[i] = mk_p(h2[i - 1].F *base1 + t[i], h2[i - 1].S *base2 + t[i]);
	}
	int st = len, en = -1;
	for (int i = 0; i < len; i++)
		if (s[i] != t[i])
			st = min(st, i), en = max(en, i);
	if (st == len) {
		cout << 0 << '\n';
		return;
	}
	int ans = 0;
	for (int k = 1; k <= n; k++) {
		bool flag = 0;
		for (int i = max(0, en - siz[k] + 1); i <= st && i + siz[k] - 1 < len; i++) {
			int j = i + siz[k] - 1;
			if (get_hash1(i, j) == hsh1[k] && get_hash2(i, j) == hsh2[k]) {
				flag = 1;
				break;
			}
		}
		if (flag)
			ans++;
	}
	for (int i = 0; i < len; i++)
		h1[i] = h2[i] = mk_p(0, 0);
	cout << ans << '\n';
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	pw[0] = mk_p(1, 1);
	for (int i = 1; i <= 1e5; i++)
		pw[i] = mk_p(pw[i - 1].F * base1, pw[i - 1].S * base2);
	cin >> n >> T;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		siz[i] = s1[i].size();
		for (int j = 0; j < siz[i]; j++) {
			hsh1[i].F = hsh1[i].F * base1 + s1[i][j];
			hsh1[i].S = hsh1[i].S * base2 + s1[i][j];
			hsh2[i].F = hsh2[i].F * base1 + s2[i][j];
			hsh2[i].S = hsh2[i].S * base2 + s2[i][j];
		}
	}
	while (T--)
		_main();
	return 0;
}
