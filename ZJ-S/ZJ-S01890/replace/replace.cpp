#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

bool tpB = 1;
int n, Q, ans, p1[N], p2[N];
string s1[N], s2[N], s, t;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> Q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		if (tpB) {
			for (int j = 0; s1[i][j]; j++)
				if (s1[i][j] != 'a' && s1[i][j] != 'b' && s2[i][j] != 'a' && s2[i][j] != 'b') {
					tpB = 0; break;
				}
		}
		s1[i] = " " + s1[i], s2[i] = " " + s2[i];
	}
	if (tpB) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; s1[i][j]; j++) {
				if (s1[i][j] == 'b') p1[i] = j;
				if (s2[i][j] == 'b') p2[i] = j;
			}
		}
		while (Q--) {
			ans = 0;
			cin >> s >> t;
			if (s.size() != t.size()) {
				cout << 0 << '\n';
				continue;
			}
			int len = s.size(), u, v;
			s = " " + s, t = " " + t;
			for (int i = 1; i <= len; i++) {
				if (s[i] == 'b') u = i;
				if (t[i] == 'b') v = i;
			}
			for (int i = 1; i <= n; i++)
				if (u - v == p1[i] - p2[i] && s.size() >= s1[i].size()) ans++;
			cout << ans << '\n';
		}
		exit(0);
	}
	while (Q--) {
		ans = 0;
		cin >> s >> t;
		if (s.size() != t.size()) {
			cout << 0 << '\n';
			continue;
		}
		int len = s.size(), st = 0, ed = 0;
		s = " " + s, t = " " + t;
		for (int i = 1; i <= len; i++)
			if (s[i] != t[i]) {
				if (st == 0) st = i;
				ed = i;
			}
		for (int i = 1; i <= n; i++) {
			int les = s1[i].size() - 1; 
			if (les == ed - st + 1) {
				bool flag = 1;
				for (int j = 1; j <= les; j++) 
					if (s1[i][j] != s[j + st - 1] || s2[i][j] != t[j + st - 1]) { flag = 0; break; }
				if (flag) ans++;
			} else if (les == len) {
				bool flag = 1;
				for (int j = 1; j <= len; j++)
					if (s1[i][j] != s[j] || s2[i][j] != t[j]) { flag = 0; break; }
				if (flag) ans++;
			} else if (les > ed - st + 1 && les <= len) {
				for (int beg = max(1, ed - les + 1); beg <= min(n - les + 1, st); beg++) {
					bool flag = 1;
					for (int j = 1; j <= les; j++)
						if (s1[i][j] != s[beg + j - 1] || s2[i][j] != t[beg + j - 1]) { flag = 0; break; }
					if (flag) ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
