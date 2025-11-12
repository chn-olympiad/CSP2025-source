#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, sum = 0, b[3] = {0};
	cin >> t;
	for (int g = 1; g <= t; g++) {
		int n, x = 0, y = 0, z = 0;
		cin >> n;
		int n2 = n / 2;
		for (int i = 0; i < n; i++) {
			int x1, y1, z1;
			cin >> x1 >> y1 >> z1;
			if (x1 > y1 && x1 > z1) {
				if (x <= n2) {
					b[sum] += x1;
					x++;
					continue;
				} else if (y1 > z1) {
					if (y <= n2) {
						b[sum] += y1;
						y++;
						continue;
					} else {
						b[sum] += z1;
						z++;
						continue;
					}
				} else {
					if (z <= n2) {
						b[sum] += z1;
						z++;
						continue;
					} else {
						b[sum]  += y1;
						y++;
						continue;
					}
				}
			} else if (y1 > x1 && y1 > z1) {
				if (y <= n2) {
					b[sum] += y1;
					y++;
					continue;
				} else if (x1 > z1) {
					if (x <= n2) {
						b[sum] += x1;
						x++;
						continue;
					} else {
						b[sum] += z1;
						z++;
						continue;
					}
				} else {
					if (z <= n2) {
						b[sum] += z1;
						z++;
						continue;
					} else {
						b[sum] += x1;
						x++;
						continue;
					}
				};
			} else if (z1 > x1 && z1 > y1) {
				if (z <= n2) {
					b[sum] += z1;
					z++;
					continue;
				} else if (x1 > y1) {
					if (x <= n2) {
						b[sum] += x1;
						x++;
						continue;
					} else {
						b[sum]  += y1;
						y++;
						continue;
					}
				} else {
					if (y <= n2) {
						b[sum] += y1;
						y++;
						continue;
					} else {
						b[sum]  += x1;
						x++;
						continue;
					}
				}
			}
		}
		sum++;
	}
	for (int i = 0; i < 3; i++) {
		cout << b[i] << endl;
	}
	return 0;
}