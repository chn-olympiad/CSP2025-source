#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int a[N];

bool cnp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, b, mn, t = 1, tt;
	cin >> n >> m;
	mn = n * m;
	for (int i = 1; i <= mn; i++) {
		cin >> a[i];
		b = a[1];
	}
	sort(a + 1, a + mn + 1, cnp);
	for (int i = 1; i <= mn; i++) {
		if (a[i] == b) {
			b = i;
			break;
		}
	}
	if (b <= n) {
		cout << 1 << " " << b;
		return 0;
	}

	while (1) {
		if (b <= n)
			break;
		b -= n;
		t++;
	}
	tt = b;
	if (t % 2 == 0)
		tt = n - b + 1;
	cout << t << " " << tt;
	return 0;
}
