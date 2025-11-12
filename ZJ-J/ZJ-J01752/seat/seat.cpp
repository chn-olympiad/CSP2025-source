#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int a[500];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int goal = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int x = 1, y = 1, fx = 1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == goal) {
			cout << y << " " << x;
			return 0;
		}
		if (fx == 1) {
			if (x != n) {
				x++;
			} else {
				y++;
				fx = 2;
			}
		} else {
			if (x != 1) {
				x--;
			} else {
				y++;
				fx = 1;
			}
		}
	}
	return 0;
}
