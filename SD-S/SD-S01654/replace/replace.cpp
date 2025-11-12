#include <bits/stdc++.h>
using namespace std;

int n, q, l, r, ans;
string pl1[5000005], pl2[5000005];
string s1, s2;
unordered_map <string, string> mp;

int main () {
	
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	
	ios :: sync_with_stdio (0);
	cin.tie (0); cout.tie (0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		mp[s1] = s2;
	}
	for (int i = 1; i <= q; i++) {
		cin >> s1 >> s2;
		if (s1.size () != s2.size ()) {
			cout << "0\n";
			continue ;
		}
		ans = 0;
		for (int j = 0; j < s1.size (); j++) {
			if (s1[j] != s2[j]) {
				l = j;
				break ;
			}
		}
		for (int j = s1.size () - 1; j >= 0; j--) {
			if (s1[j] != s2[j]) {
				r = j;
				break ;
			}
		}
		string l1 = "", l2 = "";
		for (int j = l; j < r; j++)
			l1 += s1[j], l2 += s2[j];
		pl1[l] = l1, pl2[l] = l2;
		for (int j = l; j >= 0; j--) {
			if (j != l) {
				l1 = s1[j] + pl1[j + 1], l2 = s2[j] + pl2[j + 1];
				pl1[j] = l1, pl2[j] = l2;
			}
			for (int k = r; k < s1.size (); k++) {
				l1 += s1[k], l2 += s2[k];
//				cout << l1 << " " << l2 << "\n";
				if (mp[l1] == l2) ans++;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}

/*

*/
