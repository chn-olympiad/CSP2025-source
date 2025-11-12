#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	int key = a[0], pos;
	sort(a, a + n *m);
	for (int i = 0; i < n * m; i++) {
		if (a[i] == key) {
			pos = i;
		}
	}
	if (((n * m - pos - 1) / m + 1) % 2) {
		cout << (n *m - pos - 1) / m + 1 << " " << (n *m - pos - 1) % m + 1;
	} else {
		cout << (n *m - pos - 1) / m + 1 << " " << n - (n *m - pos - 1) % m;
	}
	return 0;
}
