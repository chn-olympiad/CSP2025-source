#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int z = n * m;
	for (int i = 1; i <= z; i++) {
		cin >> a[i];
	}
	int b = a[1];
	for (int i = 1; i <= z; i++) {
		sort(a + 1, a + z + 1);
	}
	int c = 1, r = 0;
	for (int i = z; i >= 1; i--) {
		if ((c % 2 != 0 && r == n ) || (c % 2 == 0 && r == 1) ) {
			c++;
		} else {
			if (c % 2 != 0) {
				r++;
			} else {
				r--;
			}
		}

		if (a[i] == b) {
			cout << c << " " << r;
			break;
		}
	}
	return 0;
}
