#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 100005;

int n, a[N], b[N], c[N];

void solve() {
    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> a[i] >> b[i] >> c[i];

    std::vector<i64> A, B, C;
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        int max = std::max({a[i], b[i], c[i]});
        sum += max;
        if (max == a[i]) A.push_back(max - std::max(b[i], c[i]));
        else if (max == b[i]) B.push_back(max - std::max(a[i], c[i]));
        else C.push_back(max - std::max(a[i], b[i]));
    }
    
    i64 ex = 0;
    if (A.size() * 2 > n) {
    	std::nth_element(A.begin(), A.end() - n / 2, A.end());
    	ex = std::accumulate(A.begin(), A.end() - n / 2, 0LL);
	} else if (B.size() * 2 > n) {
    	std::nth_element(B.begin(), B.end() - n / 2, B.end());
    	ex = std::accumulate(B.begin(), B.end() - n / 2, 0LL);
	} else if (C.size() * 2 > n) {
    	std::nth_element(C.begin(), C.end() - n / 2, C.end());
    	ex = std::accumulate(C.begin(), C.end() - n / 2, 0LL);
	}
	
	std::cout << sum - ex << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    std::cin >> t;

    while (t--) solve();

    return 0;
}