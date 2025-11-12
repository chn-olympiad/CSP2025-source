#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define FOR(i, l, r, x) for (int i = l; i <= r; i = x)
#define DEFOR(i, l, r, x) for (int i = l; i >= r; i = x)
using namespace std;
string s[200005][2];
int after_appear[27][1000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	FOR(i, 1, n, ++i) {
		cin >> s[i][1] >> s[i][2];
	}
	FOR(p, 1, q, ++p) {
		string pst, now;
		cin >> pst >> now;
		if (pst.size() != now.size()) {
			cout << 0 << endl;
			continue;
		} 
		DEFOR(j, pst.size(), 0, --j) {
			FOR(k, 0, 25, ++k) {
				after_appear[k][j] = n + 1;
			}
		}
		int lc = n, rc = 0;
		FOR(j, 1, pst.size() - 1, ++j) {
			if (pst[j] != now[j]) {
				lc = min(lc, j);
				rc = max(rc, j);
			}
			after_appear[pst[j] - 'a'][j - 1] = j;
		}
		DEFOR(j, pst.size() - 1, 0, --j) {
			FOR(k, 0, 25, ++k) {
				if (after_appear[k][j] != j + 1)
					after_appear[k][j] = after_appear[k][j + 1];
			}
		}
		int ans = 0;
		FOR(j, 1, n, ++j) {
			int l = 0, len = s[j][1].size(), r = l + len - 1;
			char pl = s[j][1][0], pr = s[j][1][len - 1], nl = s[j][2][0], nr = s[j][2][len - 1];
			while (r < pst.size()) {
				if (l <= lc && rc <= r && pst[l] == pl && pst[r] == pr && now[l] == nl && now[r] == nr) {
					bool flag = 1;
					FOR(i, l, r, ++i) {
						if (pst[i] != s[j][1][i - l] || now[i] != s[j][2][i - l]) {
							flag = 0;
							break;
						}
					}
					if (flag) {
						ans++;
					}
				}
				l = after_appear[s[j][1][0] - 'a'][l + 1];
				r = l + len - 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}