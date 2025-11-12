#include <bits/stdc++.h>
#define int long long
#define ls p * 2
#define rs p * 2 + 1
#define mid ((l + r) / 2)
#define lson ls, l, mid
#define rson rs mid + 1, r
using namespace std;
const int M = 1e6 + 10, N = 2e5 + 10, mod = 998244353;
int n, q, ans;
string s[N][3], t1, t2;
map<int, int>mp;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> s[i][1] >> s[i][2];
	if((n <= 1000 and q <= 1000) || q == 1) {
		while(q--) {
			ans = 0;
			cin >> t1 >> t2;
			if(t1.length() != t2.length()) {
				cout << 0 << '\n';
				continue;
			}
			t1 = ' ' + t1 + ' ';
			t2 = ' ' + t2 + ' ';
			for(int i = 1;i <= n;i++) {
				for(int j = 1;j + s[i][1].length() < t1.length();j++) {
					if(s[i][1] == t1.substr(j, s[i][1].length()) and t2.substr(j, s[i][1].length()) == s[i][2]) {
						if(t1.substr(j + s[i][1].length(), t1.length() - j - s[i][1].length()) == t2.substr(j + s[i][1].length(), t1.length() - j - s[i][1].length())) {	
							if(t1.substr(1, j - 1) == t2.substr(1, j - 1)) {
								ans++;
							}
						}
					}  
				}
			}
			cout << ans << '\n';
		}
		return 0;
	}
	string g;
	for(int i = 1;i <= N;i++) {
		g = g + 'a';
	}
	for(int i = 1;i <= n;i++) {
		int l = 1, r = s[i][1].length() - 1;
		while(l < r) {
			if(s[i][1].substr(l, mid - l + 1) == g.substr(1, mid - l + 1)) l = mid + 1;
			else r = mid;
		}
		int pos1 = l;
		l = 1, r = s[i][1].length() - 1;
		while(l < r) {
			if(s[i][2].substr(l, mid - l + 1) == g.substr(1, mid - l + 1)) l = mid + 1;
			else r = mid;
		}
		int pos2 = l;
		int ch = pos2 - pos1;
		mp[ch]++;
	}
	while(q--) {
		cin >> t1 >> t2;
		if(t1.length() != t2.length()) {
			cout << 0 << '\n';
			continue;
		}
		t1 = ' ' + t1;
		t2 = ' ' + t2;
		int l = 1, r = t1.length() - 1;
		while(l < r) {
			if(t1.substr(l, mid - l + 1) == g.substr(1, mid - l + 1)) l = mid + 1;
			else r = mid;
		}
		int pos1 = l;
		l = 1, r = t2.length() - 1;
		while(l < r) {
			if(t2.substr(l, mid - l + 1) == g.substr(1, mid - l + 1)) l = mid + 1;
			else r = mid;
		}
		int pos2 = l;
		int ch = pos2 - pos1;
		cout << mp[ch] << '\n';
	}
	return 0;
}