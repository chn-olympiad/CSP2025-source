#include <bits/stdc++.h>
using namespace std;
int a[5005];
int sum = 0, n;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 3) {
		int zong = a[1] + a[2] + a[3];
		int maxn = 0;
		if (a[1] >= maxn)
			maxn = a[1];
		if (a[2] >= maxn)
			maxn = a[2];
		if (a[3] >= maxn)
			maxn = a[3];
		if (zong > 2 * maxn)
			cout << 1;
		else
			cout << 0;
	}
	return 0;
}
