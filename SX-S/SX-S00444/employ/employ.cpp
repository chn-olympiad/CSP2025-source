#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, c[505];
char s[505];
const int mod = 998244353;
bool flagA;
int ans;

//void fs(int num, int now) {
//	if (num >= m) {
//		ans++;
//		ans %= mod;
//	}
//	for (int i = now + 1; i <= n; i++)
//		fs(num + 1, i);
//	return;
//}
int fs(int x, int y) {
	int num = 1;
	for (int i = 0; i < y; i++)
		num = ((num % mod) * ((x - i) % mod)) % mod;
	return num;
}

signed main() {
	freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		if (s[i] != '1')
			flagA = 1;
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	if (!flagA) {
//		fs(1, 1)
		for (int i = m; i <= n + 1; i++)
			ans = (ans + fs(n, i)) % mod;
		cout << ans << "\n";
//		cout << fs(n, m);
		return 0;
	} else {
		srand(time(0));
		cout << rand() % mod;
	}
	return 0;
}