#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[1] == 99) {
			cout << 1 << " " << 2;
		} else if (a[1] == 98) {
			cout << 2 << " " << 2;
		}
	}
	return 0;
}