#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(false); \
cin.tie(nullptr); \
cout.tie(nullptr);
#define mod 998244353
void fr() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
}
ll p[505], n, m, c[505], ans;
string s;
int main() {
	fr();
	IOS
	bool f = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		p[i] = i;
		if (s[i] == '0') {
			f = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (f) {
		ll p = 1;
		for (int i = n; i >= 1; i--) {
			p = (p % mod) * (i % mod) % mod;
		}
		cout << p;
		return 0;
	}
	do {
		ll yl = 0, wl = 0, l = 0;
		for (int i = 1; i <= n; i++) {
			if (wl >= c[p[i]]) {
				wl++;
				continue;
			}
			if (s[i] == '1') {
				yl++;
			} else {
				wl++;
			}
			if (yl >= m) {
				l = 1;
				break;
			}
		}
		if (l)
			ans = (ans + 1) % mod;
		
	} while(next_permutation(p + 1, p + n + 1));
	cout << ans;
	return 0;
}

