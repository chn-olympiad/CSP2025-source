#include <bits/stdc++.h>
using namespace std;
long long n, a[100000], sum = 1, k = 1;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n < 3)
		return 0;
	for (long long j = 3; j < n; j++) {
		for (long long i = 1; i <= j; i++) {
			sum = sum * (n - i);
		}
	}

	cout << sum ;
}