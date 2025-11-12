#include <bits/stdc++.h>
using namespace std;
int n;
int a[5010];
long long sum = 0;
int ans = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			ans++;
		}
	}
	int maxx = 0;
	maxx = max(a[1], a[2]);
	maxx = max(maxx, a[3]);
	if (n == 3) {
		if (a[1] + a[2] + a[3] > maxx * 2) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	if (n == 4) {
		if (a[1] + a[2] + a[3] > maxx * 2) {
			sum += 1;
		}
		maxx = max(a[1], a[2]);
		maxx = max(maxx, a[4]);
		if (a[1] + a[2] + a[4] > maxx * 2) {
			sum += 1;
		}
		maxx = max(a[1], a[3]);
		maxx = max(maxx, a[4]);
		if (a[1] + a[3] + a[4] > maxx * 2) {
			sum += 1;
		}
		maxx = max(a[3], a[2]);
		maxx = max(maxx, a[4]);
		if (a[3] + a[2] + a[4] > maxx * 2) {
			sum += 1;
		}
		maxx = max(a[1], a[2]);
		maxx = max(maxx, a[3]);
		maxx = max(maxx, a[4]);
		if (a[1] + a[2] + a[3] + a[4] > maxx * 2) {
			sum += 1;
		}
		cout << sum;
		return 0;
	}
	int hh = 1, tt = 1;
	sum = 0;
	for (int i = 3; i <= ans; i++) {
		hh = 1;
		tt = 1;
		for (int j = ans; j > ans - i; j--) {
			hh *= j;
		}
		for (int k = 1; k <= i; k++) {
			tt *= k;
		}
		sum += hh / tt;
	}
	cout << sum % 998244353;
	return 0;
}
