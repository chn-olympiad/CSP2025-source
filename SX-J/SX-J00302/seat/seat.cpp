#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[105];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;//行数n列数m
	int all = n * m;
	for (int i = 1; i <= all; i++) {
		cin >> a[i];
	}
	int f = a[1], cnt = 0;
	sort(a + 1, a + 1 + all);//升序
	for (int i = all; i >= 1; i--) {
		if (a[i] == f) {
			cnt++;
			break;
		} else {
			cnt++;
		}
	}
	int c, r; //第 c 列 第 r 行
	if (cnt % n == 0) {
		c = cnt / n;
	} else {
		c = cnt / n + 1;
	}
	if (c % 2 != 0) {
		r = cnt - (c - 1) * n;
	} else {
		r = n - (cnt - (c - 1) * n) + 1;
	}
	cout << c << ' ' << r;
}
