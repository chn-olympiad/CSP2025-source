#include <bits/stdc++.h>
#define int int64_t

const int maxn = 262144;

int n, q;
std::string from[maxn], to[maxn]; 

signed main() {
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout); 
	
	std::cin >> n >> q;
	for (int i = 1; i <= n; i++) 
		std::cin >> from[i] >> to[i];
	
	while (q -- ) {
		std::string a, b;
		std::cin >> a >> b;
		
		int ans = 0;
		for (int i = 0; i < a.size(); i++)
			for (int j = 1; i + j <= b.size(); j++) 
				for (int k = 1; k <= n; k++) 
					if (from[k] == a.substr(i, j)) {
						std::string newa = a.substr(0, i) + to[k] + a.substr(i + j); 
						if (newa == b) ans += 1;
					}
	
		std::cout << ans << "\n"; 
	}
	
	return 0;
} 
