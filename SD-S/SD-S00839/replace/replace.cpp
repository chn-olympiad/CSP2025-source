//See You, My OIer Life 

#include <bits/stdc++.h>

typedef long long ll;
const ll MAXN = 1e3 + 5;

ll read() {
	ll x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + c - '0'; c = getchar();}
	return x * f;
}

std::pair<std::string, std::string> a[MAXN];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ll n = read(), q = read();
	for (int i = 1; i <= n; i++)
		std::cin >> a[i].first >> a[i].second;
	while(q--) {
		std::string x, y;
		std::cin >> x >> y;
		if(x.size() != y.size()) {
			std::cout << 0 << '\n';
			continue;
		}
		ll res = 0;
		for (int l = 0; l < x.size(); l++)
			for (int r = l; r < x.size(); r++) {
				if(x.substr(0, l) != y.substr(0, l) || x.substr(r + 1, x.size() - r) != y.substr(r + 1, x.size() - r)) {
					continue;
				}
				std::string cur = x.substr(l, r - l + 1), to = y.substr(l, r - l + 1);
				for (int i = 1; i <= n; i++) {
					if(cur == a[i].first && to == a[i].second) ++res;
				}
			}
		std::cout << res << '\n';
	}
	return 0;
}

