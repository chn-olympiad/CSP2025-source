#include <bits/stdc++.h>
using uint = unsigned;
using lint = long long;
using pii = std::pair<int, int>;
constexpr int N = 1e6 + 10;

namespace mtyt {
	int n, cnt[100];
	char s[N];
	
	void main() {
		freopen("number.in", "r", stdin);
		freopen("number.out", "w", stdout);
		std::cin.tie(0)->sync_with_stdio(0);
		std::cin >> (s + 1);
		n = std::strlen(s + 1);
		for (int i = 1; i <= n; ++i) {
			if (isdigit(s[i])) ++cnt[s[i] - '0'];
		}
		for (int i = 9; i >= 0; --i)
			for (int j = 0; j < cnt[i]; ++j)
				std::cout << i;
		std::cout << std::endl; 
	}
}

int main() {
	mtyt::main();
	return 0;
}
