#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n, q;
map<string, string> m;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		m[s1] = s2;
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int len = t1.size(), l = 0, r = len + 1;
		long long ans = 0;
		t1 = " " + t1, t2 = " " + t2;
		while (l + 1 <= n / 2 && t1[l + 1] == t2[l + 1]) l++;
		while (r - 1 >= n / 2 && t1[r - 1] == t2[r - 1]) r--;
		for (int i = 0; i <= l; i++) {
			for (int j = len + 1; j >= r; j--) {
				int L = i + 1, R = j - 1;
				string s1 = "", s2 = "";
				for (int k = L; k <= R; k++) {
					s1 += t1[k];
					s2 += t2[k];
				}
				if (m.count(s1) && m[s1] == s2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}