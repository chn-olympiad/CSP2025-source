#include <bits/stdc++.h>
using namespace std;
int a[101];

void sort(int a[], int n, int m) {
	for (int i = 1; i <= n * m; i++) {
		for (int j = i + 1; j <= n * m; j++) {
			if (a[i] < a[j])
				swap(a[i], a[j]);
		}
	}
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, x = 1, y = 1, f;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	f = a[1];
	sort(a, n, m);
	for (int i = 1; i <= n * m; i++) {
		if (f == a[i]) {
			cout << y << " " << x;
			break;
		}
		if (y % 2 == 1) {
			if (x == n)
				y++;
			else
				x++;
		} else {
			if (x == 1)
				y++;
			else
				x--;
		}
	}
	return 0;
}