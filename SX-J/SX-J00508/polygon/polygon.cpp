#include <bits/stdc++.h>
using namespace std;
int n, a[5500], sum = 0, he = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int num = n - 2;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int maxx = a[1];
	for (int i = 1;; i++) {
		he = he + a[i] + a[i + 1];
		maxx = max(maxx, max(a[i], a[i + 1]));
		if (he > maxx * 2) {
			sum++;
		}
		if (i == n) {
			i = i - num;
			he = 0;
			num++;
		}
		if (num == n) {
			he = 0;
			maxx = a[1];
			num = n;
			break;
		}
	}
	for (int i = 1;; i++) {
		he = he + a[i] + a[i + 2] ;
		maxx = max(maxx, max(a[i],  a[i + 2]));
		if (he > maxx * 2) {
			sum++;
		}
		if (i == n) {
			i = i - num;
			he = 0;
			num++;
		}
		if (num == n) {
			cout << sum;
			return 0;
		}
	}
	return 0;
}