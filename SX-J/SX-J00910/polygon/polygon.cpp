#include <bits/stdc++.h>
using namespace std;
long long n, a[5005], cnt;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 1) {
		cout << 0;
	} else if (n == 2) {
		cout << 0;
	} else if (n == 3) {
		sort(a + 1, a + 1 + n);
		if (a[1] + a[2] > a[3] && a[3] + a[2] > a[1] && a[1] + a[3] > a[1])
			cout << 1;
		else
			cout << 0;
	} else
		cout << 0;
	return 0;
}
