#include <bits/stdc++.h>
using namespace std;
int n;
int a[5050];

int main() {
	freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 1; i <= n; i++) {
		if (a[i] + a[i + 1] > a[i + 2] && a[i] + a[i + 2] > a[i + 1] && a[i + 2] + a[i + 1] > a[i ])
			ans++;
	}
	cout << ans;

	return 0;
}
