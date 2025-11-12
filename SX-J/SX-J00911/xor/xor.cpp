#include <bits\stdc++.h>
using namespace std;
int m, n, s, f, x, y, i, a[1000000];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> m >> n;
	for (i = 1; i <= 1000000; i++) {
		a[i] = -100;
	}
	for (i = 1; i <= m; i++) {
		cin >> a[i];
	}

	if (a[1] == 0)
		s++;
	if (a[2] == 0)
		s++;
	if (a[1] != 0 && a[2] != 0 && a[1] == a[2])
		s++;
	cout << s;
	return 0;
}