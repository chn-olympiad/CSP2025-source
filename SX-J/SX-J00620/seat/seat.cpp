#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], r, h = 1, l = 1;

bool px1(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}// ‰»Î
	r = a[1];
	sort(a + 1, a + 1 + n *m, px1);
	for (int i = 1; a[i] != r; i++) {
		if (l % 2 == 1) {
			if (h == n) {
				l++;
			} else {
				h++;
			}
		} else {
			if (h == 1) {
				l++;
			} else {
				h--;
			}
		}
	}
	cout << l << " " << h;
	return 0;
}