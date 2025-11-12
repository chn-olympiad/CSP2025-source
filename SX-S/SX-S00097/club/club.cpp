#include <bits/stdc++.h>
using namespace std;
int t;
int n;

struct node {
	int x, y, z, maxx, maxxx; //maxxÊýÖµ£¬maxxxÎ»ÖÃ
};

bool cmp(node aa, node bb) {
	return aa.maxx > bb.maxx;
}
node a[100010];
int aaa, bbb, ccc;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		aaa = bbb = ccc = 0;
		for (int i = 1; i <= n; i++) {
			a[i].x = a[i].y = a[i].z = a[i].maxx = a[i].maxxx = 0;
		}
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].maxx = max(max(a[i].x, a[i].y), a[i].z);
			if (a[i].x > a[i].y && a[i].x > a[i].z)
				a[i].maxxx = 1;
			else if (a[i].y > a[i].x && a[i].y > a[i].z)
				a[i].maxxx = 2;
			else if (a[i].z > a[i].x && a[i].z > a[i].y)
				a[i].maxxx = 3;
			else
				a[i].maxxx = 4;
		}
		sort(a + 1, a + n + 1, cmp);
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i].maxxx == 1) {
				if (aaa < n / 2) {
					aaa++;
					sum += a[i].maxx;
				} else if (a[i].y > a[i].z) {
					if (bbb < n / 2) {
						bbb++;
						sum += a[i].y;
					} else if (ccc < n / 2) {
						ccc++;
						sum += a[i].z;
					}
				} else {
					if (ccc < n / 2) {
						ccc++;
						sum += a[i].z;
					} else if (bbb < n / 2) {
						bbb++;
						sum += a[i].y;
					}
				}
			} else if (a[i].maxxx == 2) {
				if (bbb < n / 2) {
					bbb++;
					sum += a[i].maxx;
				} else if (a[i].x > a[i].z) {
					if (aaa < n / 2) {
						aaa++;
						sum += a[i].x;
					} else if (ccc < n / 2) {
						ccc++;
						sum += a[i].z;
					}
				} else {
					if (ccc < n / 2) {
						ccc++;
						sum += a[i].z;
					} else if (aaa < n / 2) {
						aaa++;
						sum += a[i].x;
					}
				}
			} else if (a[i].maxxx == 3) {
				if (ccc < n / 2) {
					ccc++;
					sum += a[i].maxx;
				} else if (a[i].y > a[i].x) {
					if (bbb < n / 2) {
						bbb++;
						sum += a[i].y;
					} else if (aaa < n / 2) {
						aaa++;
						sum += a[i].x;
					}
				} else {
					if (aaa < n / 2) {
						aaa++;
						sum += a[i].x;
					} else if (ccc < n / 2) {
						ccc++;
						sum += a[i].z;
					}
				}
			} else {
				if (aaa < n / 2) {
					aaa++;
					sum += a[i].x;
				} else if (bbb < n / 2) {
					bbb++;
					sum += a[i].y;
				} else {
					ccc++;
					sum += a[i].z;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
