#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
map<string,string> mp;
string S[N];

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s, t;
		cin >> s >> t;
		mp[s] = t;
	}
	while (q--) {
		int ans = 0;
		string s, t;
		cin >> s >> t;
		if (s.size() != t.size()) {
			cout << "0\n";
			continue;
		}
		for (int i = s.size()-1; i > 0; i--) {
			S[i] = s[i] + S[i+1];
		}
		string x = "";
		for (int l = 0; l < s.size(); l++) {
			if (l > 0) x += s[l-1];
			string y="", z;
			for (int r = l; r < s.size(); r++) {
				y += s[r];
				z = S[r+1];
				if (x+mp[y]+z == t) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
