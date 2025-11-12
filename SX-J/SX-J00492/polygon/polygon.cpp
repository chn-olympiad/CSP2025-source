#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[10005], sum = 0, b, mx;
	cin >> n ;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		b = a[i] + a[i + 1] + a[i + 2];
		mx = max(a[i], a[i + 1]);
		mx = max(mx, a[i + 2]);
		mx *= 2;
		if (b > mx) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}