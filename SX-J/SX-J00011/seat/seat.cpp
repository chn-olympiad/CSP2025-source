#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int nt = n * m;
	for (int i = 1; i <= nt; i++) {
		cin >> a[i];
	}
	int x = a[1], p;
	sort(a + 1, a + nt + 1, cmp);
	for (int i = 1; i <= nt; i++) {
		if (a[i] == x) {
			p = i;
			break;
		}

	}
	if (p % n == 0) {
		cout << p / n << " " << n;
	} else {
		if ((p / n + 1) % 2 == 1) {
			cout << p / n + 1 << " " << p % n;
		} else {
			cout << p / n + 1 << " " << n - p % n + 1;
		}
	}
	return 0;
}
