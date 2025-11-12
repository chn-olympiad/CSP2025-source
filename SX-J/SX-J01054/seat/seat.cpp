#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], mmax, cnt, b;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	b = n;
	for (int i = 1; i <= b * m; i++) {
		cin >> a[i];
		while (a[i] > mmax) {
			mmax = a[i];
			cnt++;
		}
		while (cnt != 1) {
			if (n + (cnt + 1) % 2 <= m)
				cout << n + (cnt + 1) % 2 << " " << (cnt + 1) - (n + (cnt + 1) % 2);
			else if ((cnt + 1) % 2 == 0)
				cout << (cnt + 1) / 2 << " " << (cnt + 1) / 2;
		}
		cout << "1" << " " << "1";
		return 0;
	}
	return 0;
}