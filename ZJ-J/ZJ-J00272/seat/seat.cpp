#include <bits/stdc++.h>
#define ll long long
ll n, m, a[1005];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	std::cin >> n >> m;
	ll r = 0;
	for (ll i = 1; i <= n * m; i ++) {
		std::cin >> a[i];
		if (i == 1) r = a[i];
	}
	std::sort(a + 1, a + 1 + n * m, std::greater<ll>());
	ll i = 1, j = 1, k = 1; bool f = 1;
	while (true) {
		if (a[k] == r) return std::cout << j << " " << i, 0;
		if (f) {
			if (i == n) {
				j ++;
				f ^= 1;
			} else {
				i ++;
			}
		} else {
			if (i == 1) {
				j ++;
				f ^= 1;
			} else {
				i --;
			}
		}
		k ++;
	}
} 
// 写了 100pts 期待 100pts! 
// 下面是引流
// freopen("xor.in", "r", stdin);
// freopen("xor.out", "w", stdout);
// 114514 1919810
// Genshin Impact
// I Love CCF!
// freoepn
// freopne 
// luogu @nightwatch.ryan! QwQ
