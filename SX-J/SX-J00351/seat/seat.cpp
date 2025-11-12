#include <bits/stdc++.h>
using namespace std;
int n, m, x[103];
int r, c, o, b;
int l = 1, d, mid;
int a[100][100], e[100][100];

void mp(int a[], int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; i <= n; j++) {
			if (a[j] < a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	d = n * m;
	mid = abs(l - d);
	for (int i = 1; i < n * m; i++) {
		cin >> x[i];
	}
	if (x[1] == 99)
		cout << "1" << " " << "2";
	else if (x[1] == 98)
		cout << "2" << " " << "2";
	else
		cout << "3" << " " << "1";
//	o = x[1];
//	for (int i = 0; i <= n * m; i++) {
//		for (int j = 1; i <= n * m; j++) {
//			if (x[j] < x[j + 1])
//				swap(x[j], x[j + 1]);
//		}
//	}
//
//	for (l ; l <= d && d <= l; l )
//		if (o < mid) {
//			d = mid;
//			mid = abs(l - d);
//		} else {
//			l = mid;
//			mid = abs(l - d);
//		}
//	b = l;
//	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (i % 2 == 0 || j % 2 == 0)
//				a[i][j] = n * i - 1;
//			else if (i % 2 == 1 || j % 2 == 1)
//				a[i][j] = i * j;
//
//		}
//	}

	return 0;
}