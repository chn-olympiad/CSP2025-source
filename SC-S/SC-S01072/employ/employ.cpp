#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int c[1010];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, res = 0, ans = 0;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
		if(c[i] != 0) ans++;
	}
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != '1') {
			res = 1;
			break;
		}
	}
	if(n == m) {
		if(res == 1 || ans != n) cout << 0;
		else {
			long long t = 1;
			for(int i = 1; i <= n; i++) {
				t *= i;
				t %= mod;
			}
			cout << t;
		}
	}
	if(res == 0) {
		cout << ans - 1;
	}
	if(m == 1) {
		int ye = 0, cnt = 0;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '1') {
				ye = i;
				break;
			}
		}
		sort(c + 1, c + n + 1, greater<int>());
		for(int i = 1; i <= n; i++) {
			if(c[i] >= ye) cnt++;
		}
		cout << cnt;
	}
	return 0;
}