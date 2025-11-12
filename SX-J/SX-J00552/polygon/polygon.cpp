#include <bits/stdc++.h>
using namespace std;
int a[10000];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n, maxx = LLONG_MIN;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		maxx = max(maxx, a[i] * 1ll);
	}
	if ((a[1] + a[2] + a[3]) > (maxx * 2)) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}