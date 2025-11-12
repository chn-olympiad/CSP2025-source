#include <algorithm>
#include <iostream>
#include <string>

bool f(int a, int b);

int main() {
	freopen("number.in",  "r", stdin);
	freopen("number.out", "w", stdout);
	
	std::string result, i;
	std::cin >> i;
	for(char ch : i){
		if(ch >= 0x30 && ch < 0x40) {
			result += ch;
		}
	}
	std::sort(result.begin(), result.end(), f);
	std::cout << result;
	
	return 0x000000;
}

bool f(int a, int b) {
	return a > b;
}
