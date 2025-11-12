#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxnm = 108;
int n, m, a[maxnm];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int res = a[1], now = 0, x = 1, y = 1;
	sort(a + 1, a + n * m + 1, cmp); 
	for (int j = 1; j <= m; j++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= n; i++) {
				now++;
				if (a[now] == res) {
					x = i;
					y = j;
				}
			}
		} else {
			for (int i = n; i >= 1; i--) {
				now++;
				if (a[now] == res) {
					x = i;
					y = j;
				}
			}
		}
	}
	cout << y << ' ' << x;
	return 0;
}
