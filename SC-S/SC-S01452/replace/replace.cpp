#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, q;
string s, t;
map<string, string> mp;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	while (n--) {
		cin >> s >> t;
		mp[s] = t;
	}
	while (q--) {
		cin >> s >> t;
		int l_s = s.size();
		int l_t = t.size();
		int f = min(l_s, l_t);
		ll front_current = 0;
		ll back_current = 0;
		if (l_s != l_t) {
			cout << "0\n";
			continue;
		}
		for (int i = 0; i < f; ++i) {
			if (s[i] != t[i])	break;
			++front_current;
		}
		for (int i = 1; i <= f; ++i) {
			if (s[l_s - i] != t[l_t - i])	break;
			++back_current;
		}
		if (!back_current && !front_current && mp[s] != t){
			cout << "0\n";
			continue;
		}
		ll ans = (front_current + 1) * (back_current * 1);
		for (int i = 0; i <= front_current; ++i) {
			for (int j = 0; j <= back_current; ++j) {
				if (i + j > s.size()) {
					--ans;
					continue;
				}
				string y = s.substr(i, s.size() - i - j);
				string x = "", z = "";
				if (i) {
					x = s.substr(0, i);
				}
				if (j) {
					z = s.substr(s.size() - j - 1, j);
				}
				if (x + mp[y] + z != t && mp[y].size() == y.size()) {
					--ans;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}