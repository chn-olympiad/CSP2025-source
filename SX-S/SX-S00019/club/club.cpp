#include <bits/stdc++.h>
using namespace std;
long long t;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (long long i = 1; i <= t; i++) {
		long long n, a, b, c, bmrs[100005] = {0}, myd[100005] = {0}, sum = 0;
		cin >> n;
		for (long long j = 1; j <= n; j++) {
			cin >> a >> b >> c;
			if (a >= b && a >= c) {
				if (bmrs[1] < n / 2) {
					myd[1] += a;
					bmrs[1]++;
				} else {
					if (b >= c) {
						if (bmrs[2] < n / 2) {
							myd[2] += b;
							bmrs[2]++;
						} else {
							myd[3] += c;
							bmrs[3]++;
						}
					} else {
						if (bmrs[3] < n / 2) {
							myd[3] += c;
							bmrs[3]++;
						} else {
							myd[2] += b;
							bmrs[2]++;
						}
					}
				}
			} else if (b >= a && b >= c) {
				if (bmrs[2] < n / 2) {
					myd[2] += b;
					bmrs[2]++;
				} else {
					if (a >= c) {
						if (bmrs[1] < n / 2) {
							myd[1] += a;
							bmrs[1]++;
						} else {
							myd[3] += c;
							bmrs[3]++;
						}
					} else {
						if (bmrs[3] < n / 2) {
							myd[3] += c;
							bmrs[3]++;
						} else {
							myd[1] += a;
							bmrs[1]++;
						}
					}
				}
			} else if (c >= b && c >= a) {
				if (bmrs[3] < n / 2) {
					myd[3] += c;
					bmrs[3]++;
				} else {
					if (a >= b) {
						if (bmrs[1] < n / 2) {
							myd[1] += a;
							bmrs[1]++;
						} else {
							myd[2] += b;
							bmrs[2]++;
						}
					} else {
						if (bmrs[2] < n / 2) {
							myd[2] += b;
							bmrs[2]++;
						} else {
							myd[1] += a;
							bmrs[1]++;
						}
					}
				}
			}
		}
		for (long long l = 1; l <= 3; l++) {
			sum += myd[l];
		}
		cout << sum << endl;
	}
	return 0;
}



