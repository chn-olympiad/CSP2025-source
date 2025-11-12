#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], maxi, mini;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = n; i <= m; i++) {
		if (a[i] > maxi) {
			maxi = i;
			cout << 1 << " " << 1;
		} else if (a[i] > mini) {
			mini = i;
			cout << n << " " << m;
		} else {
			cout << n << " " << (m + i) % (m - i) << endl;
		}
	}

	return 0;
}
