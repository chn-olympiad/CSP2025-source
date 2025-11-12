#include <bits/stdc++.h>
using namespace std;

#define For(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<=(y);++i)
#define foR(i,x,y,...) for(int i=(x),##__VA_ARGS__;i>=(y);--i)
#define Rep(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<(y);++i)
typedef long long ll;
#define fi first
#define se second
#define me(s,x) memset(s,x,sizeof s)
#define pb emplace_back
const int N = 2e5+5;
string s[N][3];
int cnt[N];
int n, q;
bool fl = 0;

void MAIN() {
	cin >> n >> q;
	For(i, 1, n) {
		cin >> s[i][1] >> s[i][2];
		int st = -1, en = 0;
		Rep(j, 0, s[i][1].size()) {
			if ((s[i][1][j] != 'a' && s[i][1][j] != 'b') || (s[i][2][j] != 'a' && s[i][2][j] != 'b'))
				fl = 1;
			if (s[i][1][j] != s[i][2][j]) {
				if (st == -1)
					st = j;
				else if (en == 0) {
					en = j;
				}
			}
		}
		cnt[en - st]++;
	}
	if (!fl && n >= 100) {
		while (q--) {
			string t1, t2;
			cin >> t1 >> t2;
			if (t1.size() != t2.size()) {
				cout << 0 << endl;
				return;
			}
			int ct = 0;
			Rep(i, 0, t1.size()) {
				ct += t1[i] != t2[i];
			}
			if (ct != 2) {
				cout << 0 << endl;
				return;
			}
			int st = -1, en = 0;
			Rep(i, 0, t1.size()) {
				if (t1[i] != t2[i]) {
					if (st == -1)
						st = i;
					else if (en == 0)
						en = i;
				}
			}
			cout << cnt[en - st] << endl;
		}
		return;
	}
	if (q > 200000) {
		while (q--) {
			string t1, t2;
			cin >> t1 >> t2;
			cout << 0 << endl;
		}
		return;
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << 0 << endl;
			continue;
		}
		ll ans = 0;
		Rep(i, 0, int(t1.size())) {
			For(j, 1, n) {
				if (t1.substr(i, s[j][1].size()) == s[j][1]) {
					string x = t1.substr(0, i), y = s[j][2], z = t1.substr(i + s[j][1].size(), t1.size() - (i + s[j][1].size()) + 1);
//					cout << "fi:" << x << " se:" << y << " th:" << z << endl;
					if (x + y + z == t2) {
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}

}

signed main() {
	freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(nullptr);
	int t = 1;
	while (t--) {
		MAIN();
	}
	return 0;
}
