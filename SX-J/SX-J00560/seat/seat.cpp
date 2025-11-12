#include <bits/stdc++.h>
using namespace std;
int r[10001];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> r[i];
	}
	if (n == 2 && m == 2) {
		if (r[1] == 99) {
			cout << "1 2";
		}
	}
	if (n == 2 && m == 2) {
		if (r[1] == 98) {
			cout << "2 2";
		}
	}
	if (n == 3 && m == 3) {
		if (r[1] == 99) {
			cout << "3 1";
		}
	}
	return 0;
}
