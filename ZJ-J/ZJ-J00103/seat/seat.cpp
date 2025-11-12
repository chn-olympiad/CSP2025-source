#include <bits/stdc++.h>

//#define int long long
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

constexpr int N = 20;
int n, m, a[N * N]; 

int main() {
	freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) std::cin >> a[i];
	int val = a[1];
	std::sort(a + 1, a + 1 + n * m, std::greater<int> ());
	int pos = 0;
	for (int i = 1; i <= n * m; ++i) 
		if (a[i] == val) {
			pos = i;
			break ; 
		}
	int x = pos / n, y = pos % n;
	if (y == 0) {
		if (x & 1) std::cout << x << " " << n << "\n";
		else std::cout << x << " " << 1 << "\n"; 
	}
	else {
		if (x & 1) std::cout << x + 1 << " " << n - y + 1 << "\n";
		else std::cout << x + 1 << " " << y << "\n"; 
	}
	return 0;
}

