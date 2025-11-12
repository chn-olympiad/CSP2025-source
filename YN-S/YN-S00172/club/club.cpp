#include <bits/stdc++.h>
using namespace std;
int aq, aw, ae;

struct A  {
	int a1, a2, a3, W, L, M;
};

bool f(A n, A m) {
	if (n.W > m.W) {
		return 1;
	} else if (n.W < m.W) {
		return 0;
	} else if ( n.L > m.L) {
		return 1;
	} else if ( n.L < m.L) {
		return 0;
	} else if ( n.M > m.M) {
		return 1;
	}
	return 0;
}

int max(int a, int b, int c) {
	if (a >= b && a >= c ) {
		return 1 + a * 10;
	}
	if (b >= a && b >= c ) {
		return 2 + b * 10;
	}
	if ( c >= a && c >= b) {
		return 3 + c * 10;
	}
	return 0;
}

int max2(int a, int b, int c) {
	if (a >= b && b >= c || a <= b && b <= c) {
		return b;
	}
	if (a >= c && c >= b || a <= c && c <= b) {
		return c;
	}
	if (b >= a && a >= c || b <= a && a <= c) {
		return a;
	}
	return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, n2;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		n2 = n / 2;
		A a[n + 1] = {0};
		int b[4] = {0}, num = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[j].a1 >> a[j].a2 >> a[j].a3;
			a[j].L = max(a[j].a1, a[j].a2, a[j].a3);
			a[j].M = max2(a[j].a1, a[j].a2, a[j].a3);
			a[j].W = a[j].L / 10 - a[j].M;
		}
		sort(a + 1, a + n + 1, f);
		for (int j = 1; j <= n; j++) {
			if (b[a[j].L % 10] + 1 <= n2) {
				b[a[j].L % 10]++;
				num += a[j].L / 10;
			} else {
				num += a[j].M;
			}
		}
		cout << num << endl;
	}
	return 0;
}