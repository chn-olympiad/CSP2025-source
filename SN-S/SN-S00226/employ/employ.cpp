// 张思晨-SN-S00226-西安滨河学校 
#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 600;
const int Mod = 998244353;
int n, m;
char gt;
bool s[N];
int c[N];
int k = 0;
bool check = 0;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i != n; ++i) {
		cin >> gt;
		s[i] = (gt == '1' ? 1 : 0);
		if (s[i] == 0)
			check = 1;
	}
	for (int i = 0; i != n; ++i) {
		cin >> c[i];
		if (c[i] == 0)
			++k;
	}
	
	if (m + k > n) {
		cout << 0 << endl;
		return 0;
	}
	// A
	if (check == 0) {
		int ans = 1;
		for (int i = 2; i <= (n - k); ++i) {
			ans *= i;
			ans %= Mod;
		}
		for (int i = n - m - k + 1; i <= n - m; ++i) {
			ans *= i;
			ans %= Mod;
		}
		cout << ans << endl;
	}
	
	
	return 0;
}
