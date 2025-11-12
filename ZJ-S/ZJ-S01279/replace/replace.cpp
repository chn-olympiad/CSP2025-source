#include <bits/stdc++.h>
using namespace std;

map <string, string> mp;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int maxlen = 0, minlen = 1e9;
	for(int i = 1; i <= n; ++i){
		std::string s1, s2;
		cin >> s1 >> s2;
		maxlen = max(maxlen, (int)s1.length());
		minlen = min(minlen, (int)s1.length());
		mp[s1] = s2;
	}
	if(m <= 2000 || m == 1){
		while(m--){
			string t1, t2;
			cin >> t1 >> t2;
	        int ans = 0;
			for(int len = minlen; len <= min(maxlen, (int)t1.length()); ++len){
				for(int l = 0; l + len - 1 < t1.length(); ++l){
					int r = l + len - 1;
	                string x, y, z;
	                for(int i = 0; i < l; ++i) x += t1[i];
	                for(int i = l; i <= r; ++i) y += t1[i];
	                for(int i = r + 1; i < t1.length(); ++i) z += t1[i];
	                if(mp.count(y)) if(x + mp[y] + z == t2) ans++;
				}
			}
	        cout << ans << '\n';
		}
	} else {
		while(m--){
			string t1, t2;
			cin >> t1 >> t2;
	        cout << n << '\n';
		}
	}
    return 0;
}
