#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>

using ll = long long int;
const int MAXN = 5e6 + 10;
const int mod = 217636919, base = 131;

int n, q;

ll p[MAXN], h1[MAXN], h2[MAXN], a[MAXN], b[MAXN], sz[MAXN];

void init (int x) {
	p[0] = 1;
	for (int i = 1; i <= x; i++)
		p[i] = p[i - 1] * base % mod;
}

ll gethash (ll hash[], int l, int r) {
	return (hash[r] - hash[l - 1] * p[r - l + 1] % mod + mod) % mod;
}

int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> n >> q;
	
	init(5e6);
	
	for (int i = 1; i <= n; i++) {
		std::string s1, s2; ll h1 = 0, h2 = 0;
		std::cin >> s1 >> s2;
		for (int j = 0; j < s1.size(); j++)
			h1 = h1 * base % mod, h1 = (h1 + s1[j] - 'a' + 1) % mod;
		for (int j = 0; j < s2.size(); j++)
			h2 = h2 * base % mod, h2 = (h2 + s2[j] - 'a' + 1) % mod;
		
		a[i] = h1, b[i] = h2;
		sz[i] = s1.size();
	}
	
	while (q--) {
		std::string s1, s2; std::cin >> s1 >> s2;
		int len = s1.size(), ans = 0;
		s1 = " " + s1, s2 = " " + s2;
		
		for (int i = 1; i <= len; i++) {
			h1[i] = (h1[i - 1] * base % mod + s1[i] - 'a' + 1) % mod;
			h2[i] = (h2[i - 1] * base % mod + s2[i] - 'a' + 1) % mod;
		}
		
		for (int i = 1; i <= len; i++) {
			if (gethash(h1, i + 1, len) != gethash(h2, i + 1, len)) continue;
			for (int j = 1; j <= n; j++) {
				if (i - sz[j] + 1 < 1) continue;
				if (gethash(h1, i - sz[j] + 1, i) == a[j] && gethash(h2, i - sz[j] + 1, i) == b[j] && gethash(h1, 1, i - sz[j]) == gethash(h2, 1, i - sz[j]))
					ans++;
			}
		}
		
		for (int i = 1; i <= len; i++)
			h1[i] = h2[i] = 0;
		
		std::cout << ans << '\n';
	}
	
	
	
	return 0;
}