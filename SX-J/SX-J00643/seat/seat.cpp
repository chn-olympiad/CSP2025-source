#include <bits/stdc++.h>
using namespace std;
int a[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;


	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}


	int axm = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	if (axm == a[1]) {
		cout << 1 << " " << 1;
		return 0;
	}
	int ns;
	for (int i = 1; i <= n * m; i++) {
		if (axm == a[i])
			ns = i;
	}
	int nn, nm;

	if (ns == 1) {
		cout << 1 << " " << 1;
		return 0;
	}
	if (n == 1) {
		cout << ns << " " << 1;
		return 0;
	}
	if (m == 1) {
		cout << 1 << " " << ns;
		return 0;
	}
	if (n == 2 && m == 2) {
		if (ns == 2)
			cout << 1 << " " << 2;
		if (ns == 3)
			cout << 2 << " " << 2;
		if (ns == 4)
			cout << 2 << " " << 1;
		return 0;
	}
	if (ns == m * n) {
		if (m % 2 == 0)
			cout << m << " " << 1;
		else
			cout << m << " " << n;
		return 0;
	}

	if (ns % n != 0)
		nm = ns / n + 1;
	else
		nm = ns / n;
	if (nm % 2 != 0) {
		if (ns % n == 0)
			nn = n - ns % n;
		else
			nn = ns % n;
	} else {
		if (ns % n != 0)
			nn = n - ns % n + 1;
		else
			nn = n - ns % n;
	}
	cout << nm << " " << nn;
	return 0;
}
