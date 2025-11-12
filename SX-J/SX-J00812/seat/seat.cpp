#include <bits/stdc++.h>
using namespace std;

int sww(int n, int a[]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i] = max(a[j], a[j + 1]);
		}
	}
	return a;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a, b, x, l, h;
	cin >> a >> b >> e = 0;
	int sw[a * b], n = a * b;
	for (int i = 1; i <= n; i++) {
		cin >> sw[i];
	}
	x = sw[1];
	sw = sww(n, sw);
	return 0;
}
