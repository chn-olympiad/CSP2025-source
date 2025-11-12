#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define X 131
const ll N = 2e5 + 5;
ll n, q;
std::map<std::string, std::string> mp;
ll gen(std::string &s) {
	ll vip = s.size();
	ull ans = 0;
	ull beiz = 1;
	for (ll i = 0; i < vip; i ++) {
		ans = ans + (s[i] - 48) * beiz;
		beiz *= X;
	}
	return ans;
} 
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	// 感觉能拿个暴力分，直接开写 [15:08]
	// TODO 用个 hash 可以多拿 30pts 等会儿再说 [15:14] 
	// hhh 15min 拿了 10pts 
	std::cin >> n >> q; 
	for (ll i = 1; i <= n; i ++) {
		std::string x, y;
		std::cin >> x >> y;
		mp[x] = y;
	}
	while (q --) {
		std::string p1, p2;
		std::cin >> p1 >> p2;
		ll ans = 0, sz = p1.size();
		for (ll i = 0; i < sz; i ++) {
			for (ll j = i; j < sz; j ++) {
				std::string fg, hi;
				bool f = 0;
				for (ll k = 0; k < i; k ++) 
					if (p1[k] != p2[k]) {
						f = 1; break;
					}
				for (ll k = j + 1; k < n; k ++) 
				 	if (p1[k] != p2[k]) {
						f = 1; break;
					}
				if (f) continue;
				for (ll k = i; k <= j; k ++) fg += p1[k], hi += p2[k];
				if (mp[fg] == hi) {
					ans ++;
				}
			}
		}
		std::cout << ans << "\n";
	}
}
// [15:29] total = 50pts
