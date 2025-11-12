#include <iostream>
#include <cstdio>
#include <algorithm>

bool cmp(int a, int b) {
	return a > b;
}

int n, m;
int grd[120];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	std::cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		std::cin >> grd[i];
	}
	int target = grd[0];
	int cnt = 0, j = 0, x = n * m;
	std::sort(grd + 0, grd + x, cmp);
	for (int i = 0; i < m; i++) {
		if (j == 0) {
			for (j = 0; j < n; j++) {
				if (grd[cnt] == target) {
					std::cout << i + 1 << ' ' << j + 1;
					return 0;
				}
				cnt++;
			}
			j--;
		} else if (j == n - 1) {
			for (j = n - 1; j >= 0; j--) {
				if (grd[cnt] == target) {
					std::cout << i + 1 << ' ' << j + 1;
					return 0;
				}
				cnt++;
			}
			j++;
		}
	}
	return 0;
}
