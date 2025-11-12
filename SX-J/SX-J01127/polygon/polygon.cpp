#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n, a[5009], s = 0, maxx = 0, sum = 0;
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (long long i = 0; i < n; i++) {
		for (long long t = 3;  t <= n; t++) {
			s = 0;
			maxx = 0;
			for (long long j = i; j < i + t; j++) {
				s += a[j];
				if (a[j] > maxx)
					maxx = a[j];
			}
		}
		if (s > 2 * maxx) {
			sum++;
		}
		sum = sum % 998244353;
	}
	cout << sum;
}