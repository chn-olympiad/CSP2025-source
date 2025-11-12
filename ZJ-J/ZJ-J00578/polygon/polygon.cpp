// fake
// I had a great idea before, but I give up.
// I think it can get 60 points.
// 4*(10+5) = 60

#include <iostream>
#include <fstream>
#include <algorithm>

namespace noip {
typedef long long Int;

Int n, a[5005], f[5005][5005] {}, x, s, ans, pianfen;
Int P = 998244353;
Int zuhe[5005];

void main() {
	std::freopen("polygon.in", "r", stdin);
	std::freopen("polygon.out", "w", stdout);
	
	std::cin >> n;
	for (Int i = 1; i <= n; i++) std::cin >> a[i];
	
	std::sort(a+1, a+n+1);
	
	pianfen = 0;
	for (Int i = 1; i <= n; i++) pianfen += a[i];
	if (pianfen == n) {
		// pianfen
		zuhe[0] = 1;
		for (Int i = 1; i <= n; i++)
			zuhe[i] = (zuhe[i-1]*(n-i+1)/i) % P;

		pianfen = 0;
		for (Int i = 3; i <= n; i++) (pianfen += zuhe[i]) %= P;
		std::cout << pianfen << std::endl;
		return;
	}
	
	for (Int i = 0, p, c; i <= (1<<n); i++) {
		x = i, p = 1, c = 0;
		s = 0;
		for (; x > 0; x /= 2, p++) 
			if (x%2) s += a[p], c++;
		if (c < 3) continue;
		
		// std::cout << i << " " << s << " " << p << std::endl;
		if (s > 2*a[p-1]) ans = (ans+1)%P;
	}
	
	std::cout << ans << std::endl;
}
} int main() {
	noip::main();
	return 0;
}
