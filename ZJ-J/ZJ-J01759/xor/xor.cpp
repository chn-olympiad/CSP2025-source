#include <iostream>
#include <cstdio>

namespace noip {
typedef long long ll;
constexpr ll MAX_N = 500000;
ll a[1+MAX_N];
ll f[1+MAX_N];

void main() {
	std::freopen("xor.in", "r", stdin);
	std::freopen("xor.out", "w", stdout);
	
	ll n, k; std::cin >> n >> k;
	
	for (ll i = 1; i <= n; i++)
		std::cin >> a[i];
		
	for (ll i = 1; i <= n; i++) {
		ll sum = a[i]; f[i] = f[i-1];
		if (sum == k) f[i] = f[i-1]+1;
		for (ll j = i-1; j >= 1; j--) {
			sum = sum^a[j];
			if (sum == k) {
				f[i] = std::max(f[j-1]+1, f[i]);
			}
		}
		std::cout << f[i] << ' ';
	}
	
	std::cout << f[n];
}
}

int main() {
	noip::main();
	return 0;
}
