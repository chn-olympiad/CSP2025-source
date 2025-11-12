#include <bits/stdc++.h>
using namespace std;
int n, m;	//的行数与列数
int c, r;	//第 c 列第 r 行
int a[225];
int aa[15][15];
int aaa;//小r的成绩；

double cmp(int q, int w) {
	return q > w;
}

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	aaa = a[0];
	sort(a + 1 - 1, a + n *m, cmp);
	for (int i = 0, nn = 0, mm = 0; i < n * m ; i++) {
		if (mm % 2 == 0) {
			nn--;
		} else {
			nn++;
		}
		if (nn > n) {
			nn = n;
			mm++;
		} else if (nn < 1) {
			nn = 1;
			mm++;
		}
		aa[nn][mm] = a[i];
		if (aaa == aa[nn][mm]) {
			cout << mm << ' ' << nn;
			return 0;
		}
	}
	return 0;
}