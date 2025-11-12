// 吴昱胤 SN-S00113 西安铁一中国际合作学校
// By 0x0F
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long
string sa[200010], sb[200010];
string s[200010], t[200010];
map<string, int> mp; 
void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> sa[i] >> sb[i];
		mp[sa[i] + sb[i]]++;
	}
	for (int i = 1; i <= q; i++) {
		cin >> s[i] >> t[i];
		int sz = s[i].size();
		int pl = sz, pr = 1;
		int ans = 0;
		for (int w = 0; w < sz; w++) if (s[i][w] != t[i][w]) pr = w;
		for (int w = sz - 1; ~w; w--) if (s[i][w] != t[i][w]) pl = w;
		pl++, pr++;
		for (int ii = 1; ii <= pl; ii++)
			for (int j = max(ii, pr); j <= sz; j++) {
				string s1 = "", s2 = "";
				for (int k = ii; k <= j; k++) s1 += s[i][k - 1];
				for (int k = ii; k <= j; k++) s2 += t[i][k - 1];
				ans += mp[s1 + s2];
//				cout << i << " " << j << endl; 
//				cout << s1 + s2 << endl;
			}
		cout << ans << endl;
	}
} 
int main() {
	ios :: sync_with_stdio(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	solve();
	return 0;
}

