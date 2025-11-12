#include <bits/stdc++.h>
#define int long long
using namespace std;

const int base1 = 131, Mod1 = 998442353, base2 = 998244353, Mod2 = 1e9 + 7;
int ans, n, q;
map<pair<int, int> > mp;

signed main(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string u, v;
		cin >> u >> v;
		for(int j = u.size() - 1; j >= 0; j--){
			hsh1 = (hsh1 * base1 + v[j]) % Mod1;
			hsh1 = (hsh1 * base1 + u[j]) % Mod1;
			hsh2 = (hsh2 * base2 + v[j]) % Mod2;
			hsh2 = (hsh2 * base2 + u[j]) % Mod2;
		}
	}

	while(q--){
		string s, t;
		int ans = 0;
		cin >> s >> t;
		for(int j = 0; j < s.size(); j++){
			cal[j] = (s[j] == t[j]);
			cal2[j] = (s[j] == t[j]);
			if(j) cal[j] &= cal[j - 1];
		}
		for(int j = s.size() - 2; j >= 0; j--){
			cal2[j] = cal2[j] & cal2[j + 1];
		}
		for(int i = s.size() - 1; i >= 0; i--){
			int tmp = 0;
			for(int j = i; j >= 0; j--){
				hsh1 = (hsh1 * base1 + t[j]) % Mod1;
				hsh1 = (hsh1 * base1 + s[j]) % Mod1;
				hsh2 = (hsh2 * base2 + t[j]) % Mod2;
				hsh2 = (hsh2 * base2 + s[j]) % Mod2;
				tmp++;
				if(tmp % 2 == 0 && (!j || cal[j - 1]) && (i != s.size() - 1 || cal2[i + 1]))
					ans += mp[make_pair(hs1, hsh2)];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}