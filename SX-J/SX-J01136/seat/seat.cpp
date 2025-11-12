#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], flag, pai, f, b[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1) {
			flag = a[i];
		}
	}
	sort(a + 1, a + n *m + 1, greater<int>());
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == flag) {
			pai = i;
			break;
		}
	}
	if (pai == 1) {
		cout << 1 << " " << 1;
	} else if (pai == n * m) {
		cout << n << " " << 1;
	} else if (pai <= n) {
		cout << 1 << " " << pai;
	} else if (n == 2 && m == 2) {
		if (pai == 3) {
			cout << 2 << " " << 2;
		} else {
			cout << 2 << " " << 1;
		}
	} else if (pai % n == 0 && pai % m == 0) {
		cout << pai / n << " ";
		if ((pai / n) % 2 == 0) {
			cout << pai % m + pai / m;
		} else {
			cout << pai % m;
		}
	} else {
		cout << (pai / n) + 1 << " ";
		if ((pai / n + 1) % 2 == 0) {
			cout << pai % m + pai / m;
		} else {
			cout << pai % m;
		}
	}
	return 0;
}
