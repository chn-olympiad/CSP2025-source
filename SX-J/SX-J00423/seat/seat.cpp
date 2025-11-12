#include <bits/stdc++.h>
using namespace std;
int n, m, a[200], r;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {

		if (a[i] == r) {
			int f = i % n, p = i / n  ;
			if (p % 2 == 0) {
				if (f == 0)
					cout << p + 1 << " " << n << endl;
				else
					cout << p + 1 << " " << f << endl;
				return 0;
			}
			if (f == 0)
				cout << p  << " " << n << endl;
			else
				cout << p + 1 << " " << n - f + 1 << endl;
		}
	}
	return 0;
}