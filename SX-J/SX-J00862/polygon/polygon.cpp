#include <bits/stdc++.h>
using namespace std;

int main() {

	int a[5000], n = 0, s = 0, o = 0, x = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] + a[i + 1] > a[i + 2] && a[i + 2] + a[i + 1] > a[i] && a[i + 2] + a[i] > a[i + 1]) {
			s = a[i + 2] - a[i + 1] - a[i - 2] + a[i + 1];
			o = a[i] + a[i] - a[i + 2];
		}
	}
	cout << s + s + o ;
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	return (0);
}
