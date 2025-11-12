#include <iostream>
#include <fstream>
#include <string>

namespace noip {
typedef long long Int;

Int t[10] {};
std::string s;

void main() {
	std::freopen("number.in", "r", stdin);
	std::freopen("number.out", "w", stdout);
	
	std::cin >> s;
	
	for (Int i = 0; i < s.size(); i++) 
		if ('0' <= s[i] && s[i] <= '9')
			t[s[i]-'0']++;
	
	for (Int i = 9; i >= 0; i--)
		for (Int j = 1; j <= t[i]; j++)
			std::cout << i;
	std::cout << std::endl;
}
} int main() {
	noip::main();
	return 0;
}
