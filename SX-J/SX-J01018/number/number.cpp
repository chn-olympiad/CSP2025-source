#include <bits/stdc++.h>
#include <istream>
int n,  x, y, b,  a[5001], d;


int main() {
	std::cin >> n ;
	y = std::size(n);
	for (int i = 1; i <= n; i++) {
		a[i] = n % 10;
		n = (n - a[i]) / 10;
	}
	for (int i = 1; i <= y; i++) {
		for (int j =  y - 1; j >= 1; j--) {
			if (a[j + 1] < a[j]) {
				int c = a[j + 1];
				a[j + 1] = a[j];
				a[j] = c;
				d++;
			}
		}
		if (d == 0) {
			break;
		}
	}
	for (int i = y; i >= 1; i--) {
		std::cout << a[i];
	}
	return 0;
}


