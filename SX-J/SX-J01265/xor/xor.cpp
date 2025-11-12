#include <bits/stdc++.h>
using namespace std;
int a[1000000];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, s = 0;
	cin >> n >> k;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int y = a[1];
	if (y == k)
		s++;
	for (long long i = 2; i <= n; i++) {
		if (a[i] == k)
			s++;
		else {
			for (int q = i; q <= i + k; q++) {
				y = ~(y &a[q]);
				if (y == k) {
					s++;
					y = a[q + 1];

				}
			}
		}
	}
	cout << s + 1;
	return 0;
}
