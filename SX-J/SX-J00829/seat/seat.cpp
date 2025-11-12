#include <bits/stdc++.h>
using namespace std;
const int N = 11111;
int a[N];
int n, m;

bool cmp(int t, int tt) {
	return t > tt;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int r1 = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r1) {
			r1 = i;
		}
	}
	int x = r1 / n + 1;
	int y = r1 % n;
	if (y == 0) {
		y = n;
		x--;
	}
	if (x % 2 == 0) {
		y = n - y + 1;
	}
	cout << x << " " << y << endl;
	return 0;
}
