#include <bits/stdc++.h>

#define int long long
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

constexpr int N = 1e5 + 10, inf = 1e14;
int n, a[N], b[N], c[N], w[N];

void solve() {
	std::cin >> n;
	int ans = 0, ca = 0, cb = 0, cc = 0; 
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i] >> b[i] >> c[i];
		if (a[i] >= max(b[i], c[i])) ans += a[i], ++ca;  
		else if (b[i] >= max(a[i], c[i])) ans += b[i], ++cb;
		else ans += c[i], ++cc;
	}
	if (ca <= n / 2 && cb <= n / 2 && cc <= n / 2) {
		return std::cout << ans << "\n", void();
	}
	int tot = 0; 
	for (int i = 1; i <= n; ++i) {
		if (ca > n / 2 && max(a[i], max(b[i], c[i])) == a[i]) w[++tot] = a[i] - max(b[i], c[i]);  
		else if (cb > n / 2 && max(a[i], max(b[i], c[i])) == b[i]) w[++tot] = b[i] - max(a[i], c[i]); 
		else if (cc > n / 2 && max(a[i], max(b[i], c[i])) == c[i]) w[++tot] = c[i] - max(a[i], b[i]);
	}
	std::sort(w + 1, w + 1 + tot);
	int tmp;
	if (ca > n / 2) tmp = ca - n / 2;
	else if (cb > n / 2) tmp = cb - n / 2;
	else tmp = cc - n / 2;
	for (int i = 1; i <= tmp; ++i) ans -= w[i];
	std::cout << ans << "\n"; 
}

signed main() {
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	int _; std::cin >> _;
	while (_ --> 0) {
		solve(); 
	}
	
	return 0; 
}

