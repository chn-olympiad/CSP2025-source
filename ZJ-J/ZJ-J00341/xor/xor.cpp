#include <iostream>
#include <map>

int ps[500005] = {};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	int n = 0;
	int k = 0;
	int ans = 0;
	std::map<int, bool> mp;
	mp[0] = true;
	std::cin >> n >> k;
	
	for (int i = 1; i <= n; ++i) {
		int num = 0;
		std::cin >> num;
		ps[i] = ps[i - 1] ^ num;
		if (mp[ps[i] ^ k]) {
			++ans;
			mp.clear();
		}
		mp[ps[i]] = true;
	}
	
	std::cout << ans;
	
	return 0;
}
