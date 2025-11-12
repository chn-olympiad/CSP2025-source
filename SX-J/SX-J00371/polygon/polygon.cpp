#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[5005] = {}, nmax = -1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int sum = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			nmax = max(a[i], a[j]);
			sum += a[j];
			if (sum >= nmax * 2)
				cnt++;
		}
		sum = 0, nmax = -1;
	}
	cout << cnt;
	return 0;
}
