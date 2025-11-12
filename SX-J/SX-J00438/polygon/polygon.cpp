#include <bits/stdc++.h>
using namespace std;
int n, sum, maxx = INT_MIN;
int a[5500];
int cnt;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > maxx) {
			maxx = a[i];
		}
	}
	if (n == 3) {
		for (int i = 1; i <= n; i++) {
			sum += a[i];
		}
		if (sum / 2.0 > maxx) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}
