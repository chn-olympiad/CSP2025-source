// fake
// This program can be O(n^2) if ccf gives a strict data.
// When the answer is 0, it will be a disaster.
// I want to make another program.
// It can search on xorbitsum not xorsum. 
// I think the last problem may be easier than this.
// But I also think it can get 60-80 points.

#include <iostream>
#include <fstream>

namespace noip {
typedef long long Int;

Int a[500005], s[500005] {}, n, k;
Int dp[500005] {};

void main() {
	std::freopen("xor.in", "r", stdin);
	std::freopen("xor.out", "w", stdout);
	
	std::cin >> n >> k;
	s[0] = 0;
	for (Int i = 1; i <= n; i++) {
		std::cin >> a[i];
		s[i] = s[i-1] ^ a[i];
	}
	
	dp[0] = 0;
	for (Int i = 1; i <= n; i++) {
		dp[i] = dp[i-1];
		for (Int j = i; j >= 1; j--) {
			// std::cout << j << "^-" << i << " is " << (s[i] ^ s[j-1]) << std::endl;
			if ((s[i] ^ s[j-1]) == k) {
				
				dp[i] = std::max(dp[j-1]+1, dp[i]);
				// std::cout << "refresh dp" << i << " to" << dp[i] << std::endl;
				break;
			}
		}
		
	}
	
	// for (Int i = 1; i <= n; i++) std::cout << dp[i] << std::endl;
	std::cout << dp[n] << std::endl;
}
} int main() {
	noip::main();
	return 0;
}
