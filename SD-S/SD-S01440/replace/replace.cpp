//
//  C baoli finish 40
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define PII pair<int, int>
#define ls(u) (u <<< 1)
#define rs(u) (u << 1 | 1)
using namespace std;

//int T = 1;
//const int N = ;
int n, q;
map<string, pair<string, int>> mp;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> q;
	string s1, s2;
	for (int i = 1; i <= n; i ++) {
		cin >> s1 >> s2;
		mp[s1] = {s2, s2.size()};
	}
	while (q --) {
		cin >> s1 >> s2;
		int n = s1.size(), ans = 0;
		for (int i = 0; i < n; i ++) {
			for (int l = 1; l <= n; l ++) {
				string t1 = s1.substr(i, l), t2 = s2.substr(i, l);
				if (mp.find(t1) != mp.end() && mp[t1].first == t2) { 
					string tt = s1.substr(0, i) + mp[t1].first + s1.substr(i + mp[t1].second, n - 1);
//					cout << tt << ' ' << s2 << '\n';
					if (tt != s2) continue;
					ans ++;
				}
			}
		}
		cout << ans << '\n';
		
	}

	return 0;
}

/*



*/

