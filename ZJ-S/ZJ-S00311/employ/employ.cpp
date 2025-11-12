#include <bits/stdc++.h>
#define ll long long
const ll N = 505;
const ll Mod = 998244353;
ll n, m, cst[N], p[N];
std::string s;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	// 有一种做法能获得 8 pts
	// 收益太低，不写了 [15:33] 
	// 发现只要 10min
	// 开 write [16:41]
	std::cin >> n >> m >> s;
	for (ll i = 1; i <= n; i ++) {
		std::cin >> cst[i];
		p[i] = i;
	} 
	ll cnt = 0;
	do {
		ll offer = 0, rej = 0; 
		for (ll i = 1; i <= n; i ++) {
			if (s[i - 1] == '0') {
				rej ++;
			} else {
				if (rej >= cst[p[i]]) {
					rej ++;
				}  else {
					offer ++;
				}
			}
		}
		if (offer >= m) {
			cnt ++;
			cnt %= Mod;
		}
	} while (std::next_permutation(p + 1, p + 1 + n));
	std::cout << cnt;
}
// [16:48] 112pts
