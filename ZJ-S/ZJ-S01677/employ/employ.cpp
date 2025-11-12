#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 600, mod = 998244353;
int n, m, c[N], a[N], daan;
string s; 
signed main() {
//	system("fc club.out club4.ans");
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	cin >> s; s = ' ' + s;
	for(int i = 1; i <= n; i ++) cin >> c[i], a[i] = i;\
	do {
		int p = 0, ans = 0, sum = 0;
		for(int i = 1; i <= n; i ++) {
			if(ans >= c[a[i]]) sum ++, ans ++;
			else if(s[i] == '0') ans ++, sum ++;
//			cout << ans << ' ' << c[a[i]];
		}
//		cout << sum << "\n";
		if(n - m >= sum) {
			daan ++, daan %= mod;
//		for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
		}
	} while(next_permutation(a + 1, a + 1 + n));
	
	cout << daan;
	return 0;
}
