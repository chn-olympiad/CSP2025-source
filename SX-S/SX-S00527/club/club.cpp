#include <bits/stdc++.h>
using namespace std;
int da;
int xiang[4];

struct chengyuan {
	int manyidu[4];
	int ercha = INT_MAX;
	int xiaocha = INT_MIN;
	int xx;
	int gy;
	int ai;
};
struct chengyuan a[100001];

bool cmp(struct chengyuan b, struct chengyuan c) {
	return b.ercha < c.ercha;
}

bool cmp2(struct chengyuan b, struct chengyuan c) {
	return b.xiaocha < c.xiaocha;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, k = INT_MIN, gyh = INT_MAX, tong;
	int agyh = INT_MAX, atong;
	cin >> t;
	for (int g = 1; g <= t; g++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			k = INT_MIN;
			for (int j = 1; j <= 3; j++) {
				cin >> a[i].manyidu[j];
				k = max(k, a[i].manyidu[j]);
			}
			for (int j = 1; j <= 3; j++) {
				if (k == a[i].manyidu[j]) {
					xiang[j]++;
					da = da + k;
					a[i].ai = j;
				} else {
					int cha = k - a[i].manyidu[j];
					if (a[i].ercha > cha) {
						a[i].ercha = min(a[i].ercha, cha);
						a[i].xx = j;
					}
					if (a[i].xiaocha < cha) {
						a[i].xiaocha = max(a[i].xiaocha, cha);
						a[i].gy = j;
					}
				}
			}
		}

		for (int j = 1; j <= 3; j++) {
			while (xiang[j] > n / 2) {
				sort(a + 1, a + n + 1, cmp);
				for (int i = 1; i <= n; i++) {
					if (xiang[a[i].xx] + 1 <= n / 2 && j == a[i].ai) {
						tong = a[i].xx;
						gyh = da - a[i].ercha;
						a[i].ercha = INT_MAX;
						break;
					}
				}
				sort(a + 1, a + n + 1, cmp2);
				for (int i = 1; i <= n; i++) {
					if (xiang[a[i].gy] + 1 <= n / 2 && j == a[i].ai) {
						atong = a[i].xx;
						agyh = da - a[i].xiaocha;
						a[i].xiaocha = INT_MAX;
						break;
					}
				}
				if (gyh >= agyh) {
					xiang[j]--;
					xiang[tong]++;
					da = gyh;
				} else {
					xiang[j]--;
					xiang[atong]++;
					da = agyh;
				}
			}
		}
		cout << da << endl;
		for (int i = 1; i <= 3; i++) {
			xiang[i] = 0;
		}
		da = 0;
		for (int i = 1; i <= n; i++) {
			a[i].gy = 0;
			a[i].xx = 0;
			a[i].ai = 0;
			a[i].ercha = INT_MAX;
			a[i].xiaocha = INT_MIN;
		}
	}
}