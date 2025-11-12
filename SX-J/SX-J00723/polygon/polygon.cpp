#include <bits/stdc++.h>
using namespace std;
int n;
int a[6000], maxx, sum;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		maxx = max(a[i], maxx);
	}
	if (maxx * 2 < sum)
		cout << 1;
	cout << 0;
	return 0;
}
