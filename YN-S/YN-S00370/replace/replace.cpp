#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define ll long long
ll n, q, ma;
bool used[N << 3];
string s[N], ss[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> ss[i];
		int len = s[i].size();
		used[len ] = 1;
	}
	while (q--) {
		string t, tt, c = "", cc = "";
		cin >> t >> tt;
		int cnt = 0, len = min(t.size(), tt.size()), ans = 0;
		short fl = 0;
		if (t.size() != tt.size()) {
			cout << 0 << "\n";
			continue;
		}
		for (int i = 0; i < len; i++) {
			if (t[i] != tt[i] && fl == 0) {
				cnt++;
				c += t[i];
				cc += tt[i];
			}
			if (t[i] == tt[i] && cnt != 0) {
				fl = 1;
			}
			if (t[i] != tt[i] && fl == 1) {
				fl = 2;
				break;
			}
		}
		if (fl == 2) {
			cout << 0 << "\n";
			continue;
		}
		if (used[cnt] == 0) {
			cout << 0 << "\n";
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (s[i] == c && ss[i] == cc || s[i] == t && ss[i] == tt) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}