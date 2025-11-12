#include <iostream>

long long num[10] = {};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	std::string str;
	std::cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] >= '0' && str[i] <= '9') {
			++num[str[i] - '0'];
		}
	}
	
	int sum = 0;
	for (int i = 9; i > 0; --i) {
		sum += num[i];
		for (int j = 0; j < num[i]; ++j) {
			std::cout << i;
		}
	}
	
	for (int i = 0; i < num[0] && sum; ++i) {
		std::cout << 0;
	}
	
	return 0;
}
