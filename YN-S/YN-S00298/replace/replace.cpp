#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long LL;
const int N = 2e5 + 10;

namespace problem {

int n, q;
std::string s[N][2], t[N][2];
void solve() {
	std::cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i][0] >> s[i][1];
	}
	for (int i = 1; i <= q; i++) {
		std::cin >> t[i][0] >> t[i][1];
		int t1 = 0, t2 = 0;
		for (int j = 0; j < t[i][0].size(); j++) {
			if (t[i][0][j] == 'b')
				t1 = j;
		}
		for (int j = 0; j < t[i][1].size(); j++) {
			if (t[i][1][j] == 'b')
				t2 = j;
		}
		if (t[i][0].size() != t[i][1].size()) {
			std::cout << 0 << "\n";
		}
		int cnt = 0;
		std::unordered_map<int, int> mp;
		for (int j =  t[i][0].size() - 1; j >= 0; j--) {
			if (t[i][0][j] != t[i][1][j]) {
				mp[j] = 1;
			} else if (mp[j + 1] == 1) {
				mp[j] = 1;
			}
			mp[j] = 0;
		}
		for (int j = 0; j < t[i][0].size(); j++) {
			if (j > 0 && t[i][0][j - 1] != t[i][1][j - 1])
				break;
			for (int o = 1; o <= n; o++) {
				int fg = 1;
				if (j + s[o][0].size() <= t[i][0].size()) {
					if (mp[j + s[o][0].size()] == 1)
						continue;
//					std::cerr << i << " " << j << " " << o << " " << s[o][0].size() << " " << t[i][0].size() << "\n";
					for (int k = 0; k < s[o][0].size(); k++) {
						if (s[o][0][k] != t[i][0][j + k] || s[o][1][k] != t[i][1][j + k]) {
//							std::cerr << k << "\n";
							fg = 0;
							break;
						}
					}
					std::cerr << fg << "fg\n";
					if (fg)
						cnt++;
				}
			}
		}
		std::cout << cnt << "\n";
	}
}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	problem::solve();
	return 0;
}