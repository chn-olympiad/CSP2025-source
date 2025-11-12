#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct a {
	int num;
	int chengji;
} aa[101];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < m * n; i++) {
		cin >> aa[i].chengji;
		aa[i].num = i;
	}
	for (int i = 0; i < n * m - 1; i++) {
		for (int j = i + 1; j < n * m; j++) {
			if (aa[i].chengji < aa[j].chengji) {
				swap(aa[i], aa[j]);
			}
		}
	}
	int number;
	for (int i = 0; i < n * m; i++) {
		if (aa[i].num == 0) {
			number = i;
			break;
		}
	}
	int c, r;
	c = number / n + 1;
	cout << c << ' ';
	if (c % 2 == 1) {
		r = number % n + 1;
	} else {
		r = n - number % n;
	}
	cout << r;
	return 0;
}