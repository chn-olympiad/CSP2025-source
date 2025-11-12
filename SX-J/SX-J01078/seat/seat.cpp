#include <bits/stdc++.h>
using namespace std;
int a[110], b[110];

int cmp(int o, int p) {
	return o > p;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m,  o;
	cin >> n >> m;
	for (int i = 1; i <= n * m ; i++) {

		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n *m + 1, cmp);
	for (int i = 1; i <= n * m ; i++) {
		if (b[i] == a[1]) {
			o = i;
		}
	}
	if (o <= n) {
		cout << 1 << " " << o;
	} else if (o >= n && o <= 2 * n) {
		cout << 2 << " " << 2 * n - o + 1;
	} else if (o >= 2 * n && o <= 3 * n) {
		cout << 3 << " " << o - 2 * n;
	} else if (o >= 3 * n && o <= 4 * n) {
		cout << 4 << " " << 4 * n - o + 1;
	} else if (o >= 4 * n && o <= 5 * n) {
		cout << 5 << " " << o - 4 * n;
	} else if (o >= 5 * n && o <= 6 * n) {
		cout << 6 << " " << 6 * n - o + 1;
	} else if (o >= 6 * n && o <= 7 * n) {
		cout << 7 << " " << o - 6 * n;
	} else if (o >= 7 * n && o <= 8 * n) {
		cout << 8 << " " << 8 * n - o + 1;
	} else if (o >= 8 * n && o <= 9 * n) {
		cout << 9 << " " << o - 8 * n;
	} else if (o >= 9 * n && o <= 10 * n) {
		cout << 10 << " " << 10 * n - o + 1;
	}




	return 0;
}