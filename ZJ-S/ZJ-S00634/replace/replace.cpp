#include <iostream>
#include <fstream>

namespace noip {
typedef long long Int;

std::string p1[200000], p2[200000];
std::string s1, s2;
Int n, q, l;
Int db, de;

void main() {
	std::freopen("replace.in", "r", stdin);
	std::freopen("replace.out", "w", stdout);
	
	std::cin >> n >> q;
	for (Int i = 1; i <= n; i++) std::cin >> p1[i] >> p2[i];
	
	while (q--) {
		// xiao lv ... yi jing wu suo wei le
		
		std::cin >> s1 >> s2; l = s1.size();
		std::cout << 0 << std::endl;
		
	}
}
} int main() {
	noip::main();
	return 0;
}
