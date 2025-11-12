#include <iostream>
#include <fstream>
#include <algorithm>

namespace noip {
typedef long long Int;

Int n, m, s[101], s1, si;
Int c, r;

void main() {
	std::freopen("seat.in", "r", stdin);
	std::freopen("seat.out", "w", stdout);
	
	std::cin >> n >> m;
	for (Int i = 1; i <= n*m; i++) std::cin >> s[i];
	
	s1 = s[1];
	std::sort(s+1, s+n*m+1);
	
	for (Int i = 1; i <= n*m; i++) 
		if (s[i] == s1) {
			si = n*m-i+1;
			break;
		}
		
	c = (si+n-1) / n;
	r = c%2 ? si-c*n+n : c*n-si+1;
	std::cout << c << ' ' << r << std::endl;
}
} int main() {
	noip::main();
	return 0;
}
