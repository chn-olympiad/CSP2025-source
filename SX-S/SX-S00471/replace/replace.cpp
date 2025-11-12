#include <bits/stdc++.h>
using namespace std;
string s[200005][2], a, b;
int n, q, cnt;
map<string, string> mp;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
		if (mp[s[i][0]] == s[i][1]) {
			i--;
			n--;
		}
	}
	while (q--) {
		cnt = 0;
		cin >> a >> b;
		for (int i = 1; i <= n; i++) {
			string aa = a;
			if (a.find(s[i][0]) <= a.length() && b.find(s[i][1]) <= b.length()
			        && a.find(s[i][0]) <= a.length() == b.find(s[i][1]) <= b.length()) {
				int l = a.find(s[i][0]);
				for (int j = 0; j < s[i][1].length(); j++) {
					aa[l + j] = s[i][1][j] ;
				}
			} else if (a.find(s[i][1]) <= a.length() && b.find(s[i][0]) <= b.length()
			           && a.find(s[i][1]) <= a.length() == b.find(s[i][0]) <= b.length()) {
				int l = a.find(s[i][0]);
				for (int j = 0; j < s[i][1].length(); j++) {
					aa[l + j] = s[i][0][j];
				}
			}
			if (aa == b)
				cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}
