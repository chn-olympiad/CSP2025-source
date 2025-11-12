#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, m, c, r;
int a[N], b = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	if (n == 1 && m == 1) {
		cout << "1 1";
		return 0;
	} else if (n == 1) {
		for (int i = 2; i <= n * m; i++) {
			if (a[1] <= a[i]) {
				b = i;
				swap(a[1], a[i]);
			}
		}
		cout << "1 " << b;
	}
	return 0;
}
