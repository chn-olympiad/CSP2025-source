#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n, ans = 0;
	int a[5010];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[1] = 1) {
			ans = ((n *(n - 1 ) * ( n - 2)) / 6 ) - (((n - 2) * (n - 3) * (n - 4)) / 6);
			cout << ans;
			return 0;
		} else {
			ans = ((n *(n - 1 ) * ( n - 2)) / 6 ) - (((n - 1) * (n - 2) * (n - 3) ) / 6);
			cout << ans;
			return 0;
		}
	}

	return 0;
}