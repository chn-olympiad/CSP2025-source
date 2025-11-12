#include <bits/stdc++.h>
using namespace std;
long long n, m, xm, o;
long long a[110], mc;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	xm = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == xm) {
			mc = i;
			break;
		}
	}
	o = mc / n;

	if (mc <= n) {
		//如果在第一列之内
		cout << 1 << ' ' << mc;
	} else if (mc % n == 0) { //是n的倍数（第一个或最后一个
		if (o % 2 == 0) {
			//为偶数是在第一行
			cout << o << ' ' << 1;
		} else {
			//奇数在最后一个
			cout << o << ' ' << n;
		}
	} else {
		if ((o + 1) % 2 == 0) { //如果在偶数列得倒着
			cout << o + 1 << ' ' << n + 1 - (mc % n);
		} else {//如果在奇数列正序输出
			cout << o + 1 << ' ' << mc % n;
		}
	}

	return 0;
}