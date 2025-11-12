#include <iostream>
#include <cstdio>
#include <string>

namespace noip {
typedef long long ll;
ll n[10] {};
void main() {
	std::freopen("number.in", "r", stdin);
	std::freopen("number.out", "w", stdout);
	
	std::string s; std::cin >> s;
	
	for (ll i = 0; i < (ll)s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			n[s[i]-'0']++;
	
	for (ll i = 9; i >= 0; i--)
		while (n[i]--) std::cout << i;
}
}

int main() {
	noip::main();
	return 0;
}
