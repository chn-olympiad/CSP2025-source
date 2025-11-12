#include <bits/stdc++.h>
using namespace std;
int a[5005], n, m, id, f;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		if (a[1] + a[2] + a[3] > 2 * max(a[i], max(a[2], a[3])))
			cout << 1;
		cout << endl;
	}
	return 0;
}
