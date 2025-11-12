#include <iostream>
#include <cstdio>
#include <algorithm>

namespace noip {
typedef long long ll;
constexpr ll MAX_NM = 100;
ll a[1+MAX_NM];
void main() {
	std::freopen("seat.in", "r", stdin);
	std::freopen("seat.out", "w", stdout);
	
	ll n, m; std::cin >> n >> m;
	for (ll i = 1; i <= n*m; i++)
		std::cin >> a[i];
	
	ll tmp = a[1];
	
	std::sort(a+1, a+1+m*n, [](ll x, ll y) -> bool {
		return x > y;
	});

		
	ll w = 1;
	for (ll i = 1; i <= n*m; i++)
		if (tmp == a[i]) w = i;
	
	ll lie = (w%n == 0 ? w/n : w/n+1);
	
	if (lie % 2 == 1)
		std::cout << lie << ' ' << (w%n == 0 ? n : w%n);
	else
		std::cout << lie << ' ' << (w%n == 0 ? 1 : n-w%n+1);
}
}

int main() {
	noip::main();
	return 0;
}
