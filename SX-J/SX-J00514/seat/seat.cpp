#include <bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	int cntm = 1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int r = a[1];
	int r1;
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r) {
			r1 = i;
			break;
		}
	}
	while (r1) {
		if (r1 <= n) {
			cout << cntm << " ";
			if (cntm % 2 == 1)
				cout << r1;
			else
				cout << n - r1 + 1;
			return 0;
		}
		r1 -= n;
		cntm++;
	}
	return 0;
}
