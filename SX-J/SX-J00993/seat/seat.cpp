#include <bits/stdc++.h>
using namespace std;
const int N = 120;

struct zuowei {
	int c;
	int id;
} a[N];

int cmp(zuowei a, zuowei b) {
	return a.c > b.c;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, ai = 0, v, l, r, f = 0;
	cin >> n >> m;
	a[1].id = 1;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].c;
	}
	sort(a + 1, a + (n *m) + 1, cmp);
	l = 1;
	r = n;
	ai = 0;
	for (int i = 1; i <= m; i++) {

		if (f == 0) {
			for (int j = l; j <= r; j++) {
				ai++;
				if (a[ai].id == 1) {
					cout << i << " " << j;
					return 0;
				}
			}
		} else {
			for (int j = l; j >= r; j--) {
				ai++;
				if (a[ai].id == 1) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
		v = r;
		r = l;
		l = v;
		if (l > r) {
			f = 1;
		} else {
			f = 0;
		}
	}
	return 0;
}
