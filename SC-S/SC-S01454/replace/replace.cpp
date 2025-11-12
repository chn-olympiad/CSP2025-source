// std T3 25pts
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
map<pair<string, string>, int> mp;
int n, T;
vector<pair<int, int> > vec[N * 2];
void solve() {
	
	for(int i = 1; i <= n; i++) {
		string s, t; cin >> s >> t;
		int l = 0, r = 0, sze = s.size();
		for(int j = 0; j < sze; j++) {
			if(s[j] != t[j]) {
				l = j;
				break;
			}
		}
		for(int j = sze - 1; j >= 0; j--) {
			if(s[j] != t[j]) {
				r = j;
				break;
			}
		}
		vec[r - l - 1 + 10000].push_back({l, sze - r - 1});
	}
	while(T--) {
		string s, t; cin >> s >> t;
		int l = 0, r = 0, sze = s.size();
		for(int j = 0; j < sze; j++) {
			if(s[j] != t[j]) {
				l = j;
				break;
			}
		}
		for(int j = sze - 1; j >= 0; j--) {
			if(s[j] != t[j]) {
				r = j;
				break;
			}
		}
		int ans = 0;
		for(auto x : vec[r - l - 1 + 10000]) {
			if(x.first <= l && x.second <= sze - r - 1) ans++;
		}
		cout << ans << "\n";
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> T;
	if(n >= 1e4 || (n <= 1e3 && T == 1)) {
		solve();
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		string s, t; cin >> s >> t;
		mp[{s, t}]++;
	}
	while(T--) {
		string s, t; cin >> s >> t;
		int ans = 0;
		int sze = s.size();
		int l = 0, r = sze - 1;
		for(int i = 0; i < sze; i++) {
			if(s[i] != t[i]) {
				l = i; 
				break;
			}
		}
		for(int i = sze - 1; i >= 0; i--) {
			if(s[i] != t[i]) {
				r = i;
				break;
			}
		}
//		cout << l << " " << r << "\n";
		for(int i = 0; i <= l; i++) {
			string s1, t1;
			for(int j = i; j < r; j++) {
				s1 += s[j], t1 += t[j];
			}
			for(int j = r; j < sze; j++) {
				s1 += s[j], t1 += t[j];
				ans += mp[{s1, t1}];
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 