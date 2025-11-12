#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 2e5 + 10;
string s[N][3];
int n, Q; 
int ff = 1;
void solve () {
	string t1, t2; cin >> t1 >> t2;
	int ans = 0;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 0; j < t1.size() - s[i][1].size() + 1; j ++ ) {
			if (t1[j] == s[i][1][0]) {
//				cout << "i = " << i << " j = " << j << "\n";
				string tt = t1;
//				cout << 6;
				int f = 1;
				for (int k = 0; k < s[i][1].size(); k ++ ) {
					if (s[i][1][k] == t1[k + j]) {
						t1[k + j] = s[i][2][k];
					} else {
						f = 0;
					}
				}
				if (t1 == t2 && f) {
					ans ++;	
//					cout << "i = " << i << "\n";
				}
				t1 = tt;
			} 
		}
	}
	if (t1.size() != t2.size()) ans = 0;
	cout << ans << "\n";
}
signed main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> Q;
	for (int i = 1; i <= n; i ++ ) {
		cin >> s[i][1] >> s[i][2];
	}
	while (Q --) solve();
}
