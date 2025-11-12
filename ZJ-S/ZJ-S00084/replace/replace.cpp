#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define lop(i, a, b) for (int i = (a); i < (b); i++)
#define dwn(i, a, b) for (int i = (a); i >= (b); i--)
#define pr pair<int, int>
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
#define iosfst ios :: sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
const int N = 2e5 + 10;
int n, q, sub = 1;
vector<pr> cnt[N << 1];
string s[N][3];
signed main() {
	iosfst;
	File("replace");
	cin >> n >> q;
	rep (i, 1, n) {
		cin >> s[i][1] >> s[i][2];
		int cnt1 = 0, cnt2 = 0;
		lop (j, 0, s[i][1].size()) cnt1 += (s[i][1][j] == 'a'), cnt2 += (s[i][1][j] == 'b');
		sub &= (cnt2 == 1 && cnt1 + cnt2 == s[i][1].size());
		
		int cc1, cc2;
		lop (j, 0, s[i][1].size()) if (s[i][1][j] == 'b') cc1 = j;
		lop (j, 0, s[i][2].size()) if (s[i][2][j] == 'b') cc2 = j;
		cnt[cc1 - cc2 + N].push_back(mp(cc1, s[i][2].size() - cc2));
	}
	if (sub) {
		while (q--) {
			int ans = 0;
			string t1, t2; cin >> t1 >> t2;
			if (t1.size() != t2.size() || t1 == t2) {
				cout << "0\n";
				continue;
			}
			int cc1, cc2;
			lop (i, 0, t1.size()) if (t1[i] == 'b') cc1 = i;
			lop (i, 0, t2.size()) if (t2[i] == 'b') cc2 = i;
			int k = cc1 - cc2 + N;
			lop (i, 0, cnt[k].size()) {
				pr f = cnt[k][i];
				if (cc1 >= f.fir && t2.size() - cc2 >= f.sec) ans++;
			}
			cout << ans << '\n';
		}
		return 0;
	}
	while (q--) {
		int ans = 0;
		string t1, t2; cin >> t1 >> t2;
		if (t1.size() != t2.size() || t1 == t2) {
			cout << "0\n";
			continue;
		}
		int mn = 1e9, mx = 0;
		lop (i, 0, t1.size()) if (t1[i] != t2[i]) mn = min(mn, i), mx = max(mx, i);
		rep (i, 1, n) {
			int a = t1.find(s[i][1]), b = t2.find(s[i][2]);
//			cout << a << ' ' << b << '\n';
			if (a != b || a > t1.size() || b > t2.size() || a < 0 || b < 0) continue;
			if (a <= mn && mx < a + s[i][1].size()) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
