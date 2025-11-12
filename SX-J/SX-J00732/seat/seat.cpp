#include <bits/stdc++.h>
using namespace std;
int pts[111];
int seat[20][20];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int sum = n * m;
	for (int i = 0; i < sum; i++) {
		cin >> pts[i];
	}
	int rpts = pts[0];
	int r;
	sort(pts, pts + sum);
	int tmp[111];
	for (int i = 0; i < sum; i++) {
		tmp[i] = pts[i];
	}
	for (int i = sum; i >= 0; i--) {
		pts[i] = tmp[sum - i - 1];
	}
	for (int i = 0; i < sum; i++) {
		if (pts[i] == rpts) {
			r = i;
			break;
		}
	}
	int x = 1, y = 1;
	int f = 0;
	for (int i = 0; i < r; i++) {
		seat[x][y] = pts[i];
		if (x == n && f == 0) {
			y++;
			f = 1;
		} else if (x == 1 && f == 1) {
			y++;
			f = 0;
		} else {
			if (f == 0)
				x++;
			else
				x--;
		}
	}
	cout << y << " " << x;
	return 0;
}
