#include <iostream>
#include <algorithm>

int num[105] = {};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n = 0;
	int m = 0;
	std::cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) {
		std::cin >> num[i];
	}
	int sc = num[1];
	int odr = 0;
	
	std::sort(num + 1, num + n * m + 1);
	
	for (int i = n * m, j = 1; i >= 1; --i, ++j) {
		if (num[i] == sc) {
			odr = j;
			break;
		}
	}
	
	int x = 0;
	int y = 0;
	x = (odr - 1) / n + 1;
	y = odr - (x - 1) * n;
	if (!(x & 1)) {
		y = n - (y - 1);
	}
	
	std::cout << x << " " << y;
	
	return 0;
}
