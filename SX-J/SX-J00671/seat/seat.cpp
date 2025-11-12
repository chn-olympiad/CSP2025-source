#include <bits/stdc++.h>
using namespace std;
int n, m, hang, lie; //n为行，m为列
int a[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	int x = a[0];
	sort(a, a + n *m, cmp);
	for (int i = 0; i < n * m; i++) {
		if (a[i] == x) {
			x = i + 1;
		}
	}
	if (x % m == 0) {
		lie = x / m;
	} else {
		lie = (x + m) / m;
	}
	if ((x % m) % n == 0) {
		hang = n;
	} else {
		hang = (x % m) % n;
	}
	cout << lie << " " << hang;
	return 0;
}
