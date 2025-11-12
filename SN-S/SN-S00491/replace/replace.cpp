#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace wsq {
	int n, q;
	map<string, string> mp; 
	void main() {
		cin >> n >> q;
		for(int i = 1; i <= n; i++) {
			string s, t;
			cin >> s >> t;
			mp[s] = t;
		}
		while(q--) {
			string s, t;
			cin >> s >> t;
			int cnt = 0;
			for(auto it = mp.begin(); it != mp.end(); it++) {
				string u = it->first, v = it->second;
				string S = s;
				while(S.find(u) != -1) {
					int k = S.find(u);
					bool flag = 1;
					for(int i = k; i < k + u.size(); i++) {
						S[i] = v[i-k];
						if(t[i] != s[i])
							flag = 0;
					}
					if(S == t) cnt++;
					else if(flag) s[k] = '*', t[k] = '*';
					else break;
				}
			}
			cout << cnt << endl;
		}
	}
};

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int T = 1;
	// cin >> T;
	while(T--)
		wsq::main();
	return 0;
}
