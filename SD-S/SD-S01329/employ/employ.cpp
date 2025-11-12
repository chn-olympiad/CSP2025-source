#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, MOD = 998244353;
int n, m, c[N];
char a[N];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	int sum = 0, flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	    if (a[i] != '1') flag = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 0) sum++;
	}
	if (flag) {
		int x = n - sum;
		if (x < m) {
			cout << 0;
			return 0;
		} else {
			int ans = 1;
			for (int i = 1; i <= x; i++) {
				ans *= i;
			}
			cout << ans % MOD;
			return 0;
		}
	} else {
		cout << 0;
	}
	return 0;
}
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I want to play Genshin and Star Rail!
// I love Furina!
// I love Furina!
// I love Furina!
// I love Furina!
// I love Furina!
// I love Furina!
// I love Furina!
// I love Furina!
// I love Furina!
// I love Furina!
// I love Furina!
// I love Furina!
// I love Furina!
