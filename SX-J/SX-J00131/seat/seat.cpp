#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n = 0, m = 0, t = 0, ai = 0, p = 0;
	cin >> n >> m;
	t = n * m;
	for (int i = 1; i <= t; i++) {
		cin >> a[i];
		if (i == 1) {
			ai = a[i];
		}
	}
	sort(a + 1, a + t + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				p++;
				if (a[p] == ai) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				p++;
				if (a[p] == ai) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
