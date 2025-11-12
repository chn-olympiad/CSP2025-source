#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];

int main() {
	freopen("seat.in", "r", stin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int c = 1, r = 1;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n * m; i++) {
		if (a[1] < a[i + 1] && c % 2 == 1 && r < n)
			r++;
		else if (a[1] < a[i + 1] && c % 2 == 0 && r <= n && r > 1)
			r--;
		else if (a[1] < a[i + 1] && r == n && c < m)
			c++;
		else if (a[1] < a[i + 1] && r == 1 && c < m)
			c++;
	}
	cout << c << " " << r;
	return 0;
}
