#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>

namespace noip {
typedef long long ll;
typedef std::pair<ll, std::pair<ll, ll>> type;
constexpr ll MAX_N = 100000;
type a[1+MAX_N*3];
bool v[1+MAX_N];
ll T;
void init() {
	for (ll i = 1; i <= MAX_N; i++)
		v[i] = false;
	
}
void main() {
	std::freopen("club.in", "r", stdin);
	std::freopen("club.out", "w", stdout);
	
	ll n; std::cin >> n;
	
	for (ll i = 1; i <= n*3; i += 3)	{
		std::cin >> a[i].first; a[i].second.first = i;a[i].second.second = 1;
		std::cin >> a[i+1].first; a[i+1].second.first = i;a[i+1].second.second = 2;
		std::cin >> a[i+2].first; a[i+2].second.first = i;a[i+2].second.second = 3;
	}
		
	std::sort(a+1, a+1+n*3, [](type x, type y) -> bool {
		return x.first > y.first;
	});
	
	ll ans = 0;
	ll x[1+3] {};
	for (ll i = 1; i <= n*3; i++) {
		ll id = a[i].second.first;
		ll h = a[i].second.second;
		if (!v[id]) {
			if (x[h] >= n/2) continue;
			x[h]++;
			ans += a[i].first;
			v[id] = true;
		}
		
	
 }
	std::cout << ans << std::endl;
	
}
}

int main() {
	std::cin >> noip::T;
	while (noip::T--) {
		noip::init();
		noip::main();
	}
	return 0;
}


/*

3
4 
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
