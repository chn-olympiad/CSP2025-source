#include <bits/stdc++.h>
using namespace std;
int a[200005][5], xb[200005], maxx[200005], cnt, maxxx = -1, xbb, sum;
int a1, a2, a3, bj;
int  ct1, ct2, ct3;
int t, n;

struct node {
	int x, y;
};
node c1[200005], c2[200005], c3[200005];

bool cmp(node xx, node yy) {
	return xx.x > yy.x;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		bj = n / 2;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (a[i][j] > maxxx) {
					maxxx = a[i][j];
					xbb = j;
				}
			}
			xb[++cnt] = xbb;
			maxx[cnt] = maxxx;
			sum += maxxx;
			if (xbb == 1) {
				c1[++ct1].x = maxxx;
				c1[ct1].y = i;
			} else if (xbb == 2) {
				c2[++ct2].x = maxxx;
				c2[ct2].y = i;
			} else if (xbb == 3) {
				c3[++ct3].x = maxxx;
				c3[ct3].y = i;
			}
			xbb = 0;
			maxxx = -1;
		}
		for (int i = 1; i <= cnt; i++) {
			if (xb[i] == 1) {
				a1++;
			} else if (xb[i] == 2)
				a2++;
			else if (xb[i] == 3)
				a3++;
		}
		if (a1 <= bj && a2 <= bj && a3 <= bj) {
			cout << sum << '\n';
			for (int i = 1; i <= ct1; i++)
				c1[i].x = c1[i].y = 0;
			for (int i = 1; i <= ct2; i++)
				c2[i].x = c2[i].y = 0;
			for (int i = 1; i <= ct3; i++)
				c3[i].x = c3[i].y = 0;
			ct1 = ct2 = ct3 = 0;
			continue;
		}
		if (a1 > bj) {
			sort(c1 + 1, c1 + ct1 + 1, cmp);
			for (int i = bj + 1; i <= ct1; i++) {
				if (a[c1[i].y][2] > a[c1[i].y][3]) {
					c2[++ct2].x = a[c1[i].y][1];
					c2[ct2].y = c1[i].y;
					c1[i].x = 0;
					c1[i].y = 0;
				} else {
					c3[++ct3].x = a[c1[i].y][1];
					c3[ct3].y = c1[i].y;
					c1[i].x = 0;
					c1[i].y = 0;
				}
			}
		}
		if (a2 > bj) {
			sort(c2 + 1, c2 + ct2 + 1, cmp);
			for (int i = bj + 1; i <= ct2; i++) {
				if (a[c2[i].y][1] > a[c2[i].y][3]) {
					c1[++ct1].x = a[c2[i].y][2];
					c1[ct1].y = c2[i].y;
					c2[i].x = 0;
					c2[i].y = 0;
				} else {
					c3[++ct3].x = a[c2[i].y][2];
					c3[ct3].y = c2[i].y;
					c2[i].x = 0;
					c2[i].y = 0;
				}
			}
		}
		if (a3 > bj) {
			sort(c3 + 1, c3 + ct3 + 1, cmp);
			for (int i = bj + 1; i <= ct3; i++) {
				if (a[c1[i].y][1] > a[c1[i].y][2]) {
					c1[++ct1].x = a[c3[i].y][3];
					c1[ct1].y = c3[i].y;
					c3[i].x = 0;
					c3[i].y = 0;
				} else {
					c2[++ct2].x = a[c3[i].y][3];
					c2[ct2].y = c3[i].y;
					c3[i].x = 0;
					c3[i].y = 0;
				}
			}
		}
		sum = 0;
		for (int i = 1; i <= ct1; i++) {
			sum += a[c1[i].y][1];
		}
		for (int i = 1; i <= ct2; i++) {
			sum += a[c2[i].y][2];
		}
		for (int i = 1; i <= ct3; i++) {
			sum += a[c3[i].y][3];
		}
		cout << sum << '\n';
		for (int i = 1; i <= ct1; i++)
			c1[i].x = c1[i].y = 0;
		for (int i = 1; i <= ct2; i++)
			c2[i].x = c2[i].y = 0;
		for (int i = 1; i <= ct3; i++)
			c3[i].x = c3[i].y = 0;
		ct1 = ct2 = ct3 = 0;
	}
	return 0;
}