#include <bits/stdc++.h>
using namespace std;
int n, a[5005], t;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= 3; i++) {
		cin >> a[i];
	}
	t = 2 * max(a[1], max(a[2], a[3]));
	if (n >= 3 && a[1] + a[2] + a[3] > t)
		cout << 1;
	else
		cout << 0;
	return 0;
}
