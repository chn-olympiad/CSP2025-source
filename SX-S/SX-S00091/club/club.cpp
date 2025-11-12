#include <bits/stdc++.h>
using namespace std;

int t, g[100010][4], xi[100010] = {0}, yi[100010] = {0}, zi[100010] = {0}, x = 0, y = 0, z = 0, cntx = 0, cnty = 0,
                                                                           cntz = 0, p, xj, yj, zj, ll = 0;
int sum = INT_MAX;
int xdfs(int a) {
	sum = INT_MAX;
	for (int l = 1; l <= a; l++) {
		if (xi[l] < sum && xi[l] != 0) {
			sum = xi[l];
			a = l;
		}
	}
	return a;
}

int ydfs(int a) {
	sum = INT_MAX;
	for (int l = 1; l <= a; l++) {
		if (yi[l] < sum && yi[l] != 0) {
			sum = yi[l];
			a = l;
		}
	}
	return a;
}

int zdfs(int a) {
	sum = INT_MAX;
	for (int l = 1; l <= a; l++) {
		if (zi[l] < sum && zi[l] != 0) {
			sum = zi[l];
			a = l;
		}
	}
	return a;
}

int hh(int n) {
	xi[100010] = {0};
	yi[100010] = {0};
	zi[100010] = {0};
	x = 0;
	y = 0;
	z = 0;
	cntx = 0;
	cnty = 0;
	cntz = 0;
	xj = 0;
	yj = 0;
	zj = 0;
	for (int i = 1; i <= n; i++) {
		cin >> g[i][1] >> g[i][2] >> g[i][3];
		if (g[i][1] >= g[i][2]) {
			if (g[i][1] >= g[i][3]) {
				if (x <= n / 2) {
					xi[i] = g[i][1];
					x++;
					cntx = cntx + xi[i];
				} else {
					xj = xdfs(x);
					cntx = cntx - xi[xj];
					xi[xj] = 0;
					xi[i] = g[i][1];
					cntx = cntx + xi[i];
					if (g[xj][2] < g[xj][3]) {
						zi[xj] = g[xj][3];
						z++;
						cntz = cntz + zi[xj];
					} else {
						yi[xj] = g[xj][2];
						y++;
						cnty = cnty + yi[xj];
					}
				}
			} else {
				if (z <= n / 2) {
					zi[i] = g[i][3];
					z++;
					cntz = cntz + zi[i];
				} else {
					zj = zdfs(z);
					cntz = cntz - zi[zj];
					zi[zj] = 0;
					zi[i] = g[i][3];
					cntz = cntz + zi[i];
					if (g[zj][1] < g[zj][2]) {
						yi[zj] = g[zj][2];
						y++;
						cnty = cnty + yi[zj];
					} else {
						xi[zj] = g[zj][1];
						x++;
						cntx = cntx + xi[zj];
					}
				}
			}
		} else {
			if (g[i][2] >= g[i][3]) {
				if (y <= n / 2) {
					yi[i] = g[i][2];
					y++;
					cnty = cnty + yi[i];
				} else {
					yj = ydfs(y);
					cnty = cnty - yi[yj];
					yi[yj] = 0;
					yi[i] = g[i][2];
					cnty = cnty + yi[i];
					if (g[yj][3] < g[yj][1]) {
						xi[yj] = g[yj][1];
						x++;
						cntx = cntx + xi[yj];
					} else {
						zi[yj] = g[yj][3];
						z++;
						cntz = cntz + zi[yj];
					}
				}
			} else {
				if (z <= n / 2) {
					zi[i] = g[i][3];
					z++;
					cntz = cntz + zi[i];
				} else {
					zj = zdfs(z);
					cntz = cntz - zi[zj];
					zi[zj] = 0;
					zi[i] = g[i][3];
					cntz = cntz + zi[i];
					if (g[zj][1] < g[zj][2]) {
						yi[zj] = g[zj][2];
						y++;
						cnty = cnty + yi[zj];
					} else {
						xi[zj] = g[zj][1];
						x++;
						cntx = cntx + xi[zj];
					}
				}
			}
		}
	}
	cout << cntx + cnty + cntz << endl;
	return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	int n;
	for (int j = 1; j <= t; j++) {
		cin >> n;
		hh(n);
	}
	return 0;
}