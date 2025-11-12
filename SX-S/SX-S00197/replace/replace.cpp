#include <bits/stdc++.h>
using namespace std;
int n, q;
string sr[200005][2], s[200005][2], tr[200005][2], t[200005][2];

map < pair<string, string>, int> c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> sr[i][0] >> sr[i][1];
	int zs = 0;
	for (int i = 1; i <= q; i++) {
		cin >> tr[i][0] >> tr[i][1];
		zs += tr[i][0].size() + tr[i][1].size();
	}
	if (zs <= 1e4) {
		for (int i = 1; i <= n; i++)
			c[ {sr[i][0], sr[i][1]}]++;
		for (int i = 1; i <= q; i++) {
			tr[i][0] = ' ' + tr[i][0];
			tr[i][1] = ' ' + tr[i][1];
			int l, r;
			for (int j = 1; j < tr[i][0].size(); j++) {
				if (tr[i][0][j] != tr[i][1][j]) {
					l = j;
					break;
				}
			}
			for (int j = tr[i][0].size() - 1; j >= 1; j--) {
				if (tr[i][0][j] != tr[i][1][j]) {
					r = j;
					break;
				}
			}
			t[i][0] = t[i][1] = "";
			for (int j = l; j <= r; j++) {
				t[i][0] += tr[i][0][j];
				t[i][1] += tr[i][1][j];
			}
			int ans = c[ {t[i][0], t[i][1]}];
			for (int j = l; j >= 1; j--) {
				if (j < l) {
					t[i][0] = tr[i][0][j] + t[i][0];
					t[i][1] = tr[i][1][j] + t[i][1];
				}
				for (int k = r + 1; k < tr[i][0].size(); k++) {
					t[i][0] += tr[i][0][k];
					t[i][1] += tr[i][1][k];
					ans += c[ {t[i][0], t[i][1]}];
				}
				t[i][0] = t[i][1] = "";
				for (int k = j; k <= r; k++) {
					t[i][0] += tr[i][0][k];
					t[i][1] += tr[i][1][k];
				}
			}
			cout << ans << '\n';
		}
	} else {
		for (int i = 1; i <= n; i++) {
			sr[i][0] = ' ' + sr[i][0];
			sr[i][1] = ' ' + sr[i][1];
			int l, r;
			for (int j = 1; j < sr[i][0].size(); j++) {
				if (sr[i][0][j] != sr[i][1][j]) {
					l = j;
					break;
				}
			}
			for (int j = sr[i][0].size() - 1; j >= 1; j--) {
				if (sr[i][0][j] != sr[i][1][j]) {
					r = j;
					break;
				}
			}
			s[i][0] = s[i][1] = "";
			for (int j = l; j <= r; j++) {
				s[i][0] += sr[i][0][j];
				s[i][1] += sr[i][1][j];
			}
			c[ {s[i][0], s[i][1]}]++;
		}
		for (int i = 1; i <= q; i++) {
			tr[i][0] = ' ' + tr[i][0];
			tr[i][1] = ' ' + tr[i][1];
			int l, r;
			for (int j = 1; j < tr[i][0].size(); j++) {
				if (tr[i][0][j] != tr[i][1][j]) {
					l = j;
					break;
				}
			}
			for (int j = tr[i][0].size() - 1; j >= 1; j--) {
				if (tr[i][0][j] != tr[i][1][j]) {
					r = j;
					break;
				}
			}
			t[i][0] = t[i][1] = "";
			for (int j = l; j <= r; j++) {
				t[i][0] += tr[i][0][j];
				t[i][1] += tr[i][1][j];
			}
			cout << c[ {t[i][0], t[i][1]}] << '\n';
		}
	}
	return 0;
}
