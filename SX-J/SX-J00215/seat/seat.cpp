#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m, a[105], cmp, d, c;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n * m; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[i] < a[j]) {
				cmp = a[j];
			}
		}
	}
	d = n / 2;
	c = m / 2;
	cout << d << " " << c;




	fclose(stdin);
	fclose(stdout);
	return 0;

}