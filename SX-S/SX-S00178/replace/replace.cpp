#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define PSS pair<string, string>
#define fi first
#define se second
#define debug(x) cerr << #x << " = " << x << endl;
using namespace std;

const int N = 2e5 + 10;
int n, q;
PSS s[N], t[N];
bool typeB;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	typeB = true;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i].fi >> s[i].se;
		if (!typeB) continue;
		for (auto ch : s[i].fi) {
			if (ch != 'a' && ch != 'b') typeB = false;
		}for (auto ch : s[i].se) {
			if (ch != 'a' && ch != 'b') typeB = false;
		}
	}
	for (int i = 1; i <= q; ++i) {
		cin >> t[i].fi >> t[i].se;
		if (!typeB) continue;
		for (auto ch : t[i].fi) {
			if (ch != 'a' && ch != 'b') typeB = false;
		}for (auto ch : t[i].se) {
			if (ch != 'a' && ch != 'b') typeB = false;
		}
	}
	
	if (typeB) {
		for (int _ = 1; _ <= q; ++_) {
			string a = t[_].fi, b = t[_].se;
			if (a.size() != b.size()) {
				cout << 0 << endl;
				continue;
			}
			int pre = -1, net = -1;
			string aa = "", bb = "";
			int ans = 0;
			for (int i = 0; i < (int)a.size(); ++i) {
				if (a[i] == 'b' || b[i] == 'b') {
					if (pre == -1) pre = i;
					else {
						net = i;
						break;
					}
				}
			}
			for (int i = pre; i <= net; ++i) {
				aa += a[i];
				bb += b[i];
			}
			for (int i = 1; i <= n; ++i) {
				int fina = s[i].fi.find(aa);
				int finb = s[i].se.find(bb);
				int len = s[i].fi.size();
				if (len > (int)a.size()) continue;
				if (fina <= pre && len - (fina + net - pre + 1) <= a.size()-net-1 && fina < len && finb < len && fina == finb) {
					ans++; 
				}
			}
			cout << ans << endl;
		}
		return 0;
	}
	
	for (int _ = 1; _ <= q; ++_) {
		string a = t[_].fi, b = t[_].se;
		if (a.size() != b.size()) {
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		for (int j = 1; j <= n; ++j) {
			bool use = false;
			for (int i = 0; i < (int)a.size(); ++i) {
				if (s[j].fi[0] != a[i]) continue;
				if (s[j].se[0] != b[i]) continue;
				if (use) continue;
				bool flag = true;
				for (int z = 1; z < (int)s[j].fi.size(); ++z) {
					if (a[i+z] == s[j].fi[z] && b[i+z] == s[j].se[z]) continue;
					flag = false; break;
				}
				if (!flag) continue;
				use = true;
				for (int z = (int)s[j].fi.size() + i; z < (int)a.size(); ++z) {
					if (a[z] == b[z]) continue;
					flag = false; break;
				}
				if (flag) {
					ans ++;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}
