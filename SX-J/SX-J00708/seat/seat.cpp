#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005];
bool book[100000005];
int s = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		book[a[i]] = 1;
	}
	for (int i = 100000005; i >= 1; i--) {

		if (book[i] == 1 && i > a[1])
			s++;
		if (i == a[1])
			break;
	}
	int l = n + n;
	int z = s % l;
	int f = s % n;
	int c = (s - f) / n;
	if (z <= n)
		if (s % n == 0)
			cout << s / n << " " << n;
		else

			cout << c + 1 << " " << z;
	if (z > n)
		if (s % n == 0)
			cout << s / n << " " << 1;
		else
			cout << c + 1 << " " << 2 * n - z + 1;
	return 0;
}
