#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 100;
int n, q;
string t1, t2, s1[100100], s2[100100];
signed main() {
//	system("fc club.out club4.ans");
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) cin >> s1[i] >> s2[i];
	while(q --) {
		cin >> t1 >> t2;
		string g = t1, l = t2;
		t1 = ' ' + t1;
		int ans = 0;
		for(int i = 1; i < t1.size(); i ++) {
			
			for(int len = 0; len <= t1.size() - i; len ++) {
				string hk = "", h1 = "", h2 = "";
				for(int j = 1; j < i; j ++) {
					hk += t1[j];
				}
				for(int j = i; j < i + len; j ++) {
					h1 += t1[j];
				}
				for(int j = i + len; j < t1.size(); j ++) {
					h2 += t1[j];
				}
				for(int j = 1; j <= n; j ++) {
					if(h1 == s1[j]) {//cout << hk << ' ' << h1 << ' ' << h2 << "\n";
						if(hk + s2[j] + h2 == t2) ans ++;
					}
				}
				
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
