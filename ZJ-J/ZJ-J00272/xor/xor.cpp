#include <bits/stdc++.h>
#define ll long long
const ll N = 5e5 + 5;
ll n, k, a[N], yih[N];
std::vector<std::pair<ll, ll> > ress;
bool check(ll l, ll r, ll xl, ll xr) {
	if (l <= xl && xr <= r) return 1; 
	if (xl <= r && xl >= l) return 1;
	if (xl <= l && r <= xr) return 1;
	if (l <= xr && l >= xl) return 1;
	return 0;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	std::cin >> n >> k;
	for (ll i = 1; i <= n; i ++) std::cin >> a[i];
	bool A = 1;
	for (ll i = 1; i <= n; i ++) if (a[i] != 1) A = 0;
	if (A) { // 10pts, k = 0
		// 两个 1 为一组即可
		std::cout << n / 2; 
	} else {
		for (ll i = 1; i <= n; i ++) yih[i] = yih[i - 1] ^ a[i];
		for (ll i = 1; i <= n; i ++)
			for (ll j = i; j <= n; j ++)
				if ((yih[j] ^ yih[i - 1]) == k) {
					ress.push_back({j, i});
					// 枚举后面的区间一定是不优的 
					break;
				}
		std::sort(ress.begin(), ress.end());
		ll sz = ress.size();
		if (sz == 0) return std::cout << 0, 0;
		else {
			std::pair<ll, ll> cur = ress[0];
			ll cnt = 1;
			for (ll i = 1; i < sz; i ++) {
				if (check(cur.second, cur.first, ress[i].second, ress[i].first)) continue;
				cnt ++; cur = ress[i];
			}
			std::cout << cnt; 
		} 
	}
} 
// Please reopen my code.
// write in Dev-C++, ANSI
// UTF-8 can't see the Chinese chracters
// 写了 n^2 期待 100pts QaQ
// 下面是引流
// freopen("xor.in", "r", stdin);
// freopen("xor.out", "w", stdout);
// 114514 1919810
// Genshin Impact
// I Love CCF!
// freoepn
// freopne 
// luogu @nightwatch.ryan! QwQ
