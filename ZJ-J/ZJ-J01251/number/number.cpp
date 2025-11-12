#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	string s;
	cin >> s;
	string t = "";
	int n = s.size();
	for(int i = 0; i < n; i++) {
		if(isdigit(s[i])) {
			t += s[i];
		}
	}
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());
	int len = t.size();
	bool f = 0;
	for(int i = 0; i < len; i++) {
		if(t[i] == '0') {
			if(!f) {
				continue;
			}
		}
		f = 1;
		cout << t[i];
	}
	return 0;
}