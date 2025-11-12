#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;

	int a[110];
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int a1 = a[1];
	int sum = 1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] > a1) {
			sum++;
		}
	}
	if (sum <= n) {
		cout << "1" << " " << sum;
		return 0;
	}
	sum -= n ;
	sum += 1;
	int nx = n, ny = 2;
	for (sum = sum; sum <= 1; sum--) {
		if (ny % 2 == 0 && nx != n && nx != 1) {
			nx--;
			sum--;
		}
		if (sum <= 1) {
			cout << ny << " " << nx;
			return 0;
		}
		if (nx == 1 && ny % 2 == 0) {
			ny++;
			sum--;
		}
		if (sum <= 1) {
			cout << ny << " " << nx;
			return 0;
		}
		if (nx % 2 != 0 &&  nx != n && nx != 1) {
			nx++;
			sum--;
		}
		if (sum <= 1) {
			cout << ny << " " << nx;
			return 0;
		}
		if (nx == n && ny % 2 != 0) {
			ny++;
			sum--;
		}
		if (sum <= 1) {
			cout << nx << " " << ny;
			return 0;
		}
	}
	cout << ny << " " << nx;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
