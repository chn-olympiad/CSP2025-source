#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 10;
pair<string, string> s[N], t[N];
int n, q;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> s[i].fi >> s[i].se;
	for(int i = 1; i <= q; i++) {
		cin >> t[i].fi >> t[i].se;
		if(t[i].fi.size() != t[i].se.size()) {
			cout << "0\n";
			continue; 
		}
		int ans = 0;
		for(int j = 1; j <= n; j++) {
			for(int k = 0; k <= (int)t[i].fi.size() - (int)s[j].fi.size(); k++) {
				bool flag = true;
				//中间替换后匹配不上 
				for(int l = k; l < (int) k + (int)s[j].fi.size(); l++) {
					if(s[j].se[l - k] != t[i].se[l] || s[j].fi[l - k] != t[i].fi[l]) {
						flag = false;
						break;
					}
				}
				//前面匹配不上 
				for(int l = 0; l < k; l++) {
					if(t[i].fi[l] != t[i].se[l]) {
						flag = false;
						break;
					}
				}
				//后面匹配不上 
				for(int l = (int)k + (int)s[j].fi.size(); l < (int)t[i].fi.size(); l++) {
					if(t[i].fi[l] != t[i].se[l]) {
						flag = false;
						break;
					}
				}
				if(flag) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
