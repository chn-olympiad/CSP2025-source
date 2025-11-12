#include <bits/stdc++.h>
using namespace std;
int n, a[5002], maxx = -999;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(a[i], maxx);
	}
	sort(a + 1, a + n + 1);
	if (n == 3) {
		if (a[3] + a[2] + a[1] > maxx * 2)
			cout << 1;
		else
			cout << 0;
	}
	return 0;
}