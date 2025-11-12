#include <iostream>
int  n, m, a[10005], b, d, x, y = 1;

int main() {
	std::cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		std::cin >> a[i];
	}
	b = a[1];
	for (int i = 1; i <= n * m; i++) {
		d = 0;
		for (int j = n * m - 1; j >= 1; j--) {
			if (a[j + 1] < a[j]) {
				int c = a[j + 1];
				a[j + 1] = a[j];
				a[j] = c;
			}
		}
	}
	for (int i = n * m; i >= 1; i--) {
		if (a[i] == b) {
			b = i;
			break;
		}
	}
	while (b > n) {
		b = b - n;
		y++;
	}
	if (y % 2 == 0) {
		x = n - b + 1;
	} else {
		x = b;
	}
	std::cout << y << " " << x;
	return 0;
}