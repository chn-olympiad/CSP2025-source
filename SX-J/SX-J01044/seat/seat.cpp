#include <bits/stdc++.h>
using namespace std;
int n, m, c, r, R, a[105], kk;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	kk = n * m;
	for (int i = 1; i <= kk; i++) {
		cin >> a[i];
		if (a[i] < a[i + 1]) {
			a[i + 1] = 11;

		}
	}

	return 0;
}
