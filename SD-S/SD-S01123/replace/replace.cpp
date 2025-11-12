#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lowbit(x) (x & -x)

using namespace std;

constexpr int N = 5e6 + 5, M = 2e5 + 5;
constexpr int base = 97, mod = 1e9 + 9;

int n, q;
int nxt[N];
char s1[N], s2[N];
vector<char> s[N][3];
map<int, int> mp;

void kmp(int x1, int x2) {
	int p = 0;
	for (int i = 2; i < s[x1][x2].size(); ++i) {
		while (p && s[x1][x2][p + 1] != s[x1][x2][i]) p = nxt[p];
		if (s[x1][x2][p + 1] == s[x1][x2][i]) ++p;
		nxt[i] = p;
	}
}

void solve1() {
	int len = strlen(s1 + 1), ans = 0, L = 1, R = n;
	for (int i = 1; i <= len; ++i) {
		if (s1[i] != s2[i]) {
			L = i;
			break;
		}
	}
	for (int i = len; i > 0; --i) {
		if (s1[i] != s2[i]) {
			R = i;
			break;
		}
	}
	for (int l = 1; l <= len; ++l) {
		int w1 = 0, w2 = 0;
		for (int r = l; r <= len; ++r) {
			w1 = (w1 * base + s1[r]) % mod;
			w2 = (w2 * base + s2[r]) % mod;
			if (l <= L && r >= R) {
				ans += mp[w1 * mod + w2];
			}
		}
	}
	cout << ans << '\n';
}

void solveA() {
	int m = strlen(s1 + 1), ans = 0;
	int pl = m + 1, pr = 0;
	for (int i = m; i > 0; --i) {
		if (s1[i] != s2[i]) {
			pl = min(pl, i);
			pr = max(pr, i);
		}
	}
	if (pr == 0) {
		for (int i = 1; i <= n; ++i) {
			bool flag = true;
			for (int j = 1; j < s[i][1].size(); ++j) {
				if (s[i][1][j] != s[i][2][j]) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				break;
			}
			kmp(i, 1);
			int p = 0;
			for (int j = 1; j <= m; ++j) {
				while (p && s[i][1][p + 1] != s1[j]) p = nxt[p];
				if (s[i][1][p + 1] == s1[j]) ++p;
				if (p == s[i][1].size() - 1) {
					++ans;
					p = nxt[p];
				}
			}
		}
	} else {
		
	}
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s1 + 1 >> s2 + 1;
		int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
		s[i][1].resize(len1 + 1);
		s[i][2].resize(len2 + 1);
		for (int j = 1; j <= len1; ++j) s[i][1][j] = s1[j];
		for (int j = 1; j <= len2; ++j) s[i][2][j] = s2[j];
	}
	
	if (q == 0) { // q == 1
		cin >> s1 + 1 >> s2 + 1;
		solveA();
	} else {
		for (int i = 1; i <= n; ++i) {
			int w1 = 0, w2 = 0;
			for (int j = 1; j < s[i][1].size(); ++j) {
				w1 = (w1 * base + s[i][1][j]) % mod;
				w2 = (w2 * base + s[i][2][j]) % mod;
			}
			mp[w1 * mod + w2]++;
//			cerr << "qwq1: " << w1 << ' ' << w2 << '\n';
		}
		while (q--) {
			cin >> s1 + 1 >> s2 + 1;
			solve1();
		}
	}
	
	return 0;
}
