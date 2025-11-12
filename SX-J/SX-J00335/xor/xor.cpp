#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
int a[1010][30];
int l[1010];

void ejz(int xh, int x) {
	int ll = 1;
	while (x >= 1) {
		a[xh][ll] = x % 2;
		x /= 2;
		ll++;
	}
	l[xh] = ll - 1;
}

int yh(int aa, int bb) {
	int max_l = -1;
	for (int i = aa; i <= bb; i++) {
		if (l[i] > max_l) {
			max_l = l[i];
		}
	}
	int wq = 1, ansk = 0;
	for (int i = 1; i <= max_l; i++) {
		int zsans = a[aa][i];
		for (int j = aa + 1; j <= bb; j++) {
			if (zsans == a[j][i]) {
				zsans = 0;
			} else {
				zsans = 1;
			}
		}
		ansk += zsans * wq;
		wq *= 2;
	}
	return ansk;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int zs;
	for (int i = 1; i <= n; i++) {
		cin >> zs;
		ejz(i, zs);
	}
	/*//²âÊÔÒì»òº¯Êý£º
	int x1, y1;
	cin >> x1 >> y1;
	cout << yh(x1, y1);
	*/
	int f = 0;
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j <= n) {
			int zsf = 0;
			for (int z = j; z <= n; z++) {
				if (yh(j, z) == k) {
					f = 1;
					zsf = 1;
					//cout << j << " " << z << endl;
					j = z + 1;
					ans++;
					break;
				}
			}
			if (zsf == 0) {
				j++;
			}
		}
		if (f == 1) {
			break;
		}
	}
	cout << ans;
	return 0;
}