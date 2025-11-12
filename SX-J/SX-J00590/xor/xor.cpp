#include <bits/stdc++.h>
using namespace std;
long long len = 10005;
long long a[10005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long k;
	cin >> k;
	while (true) {
		long long sum = 0;
		cin >> a[sum];
		sum++;
	}
	for (int i = 1; i <= len; i += k) {
		for (int j = 1; j <= i ; j++) {
			for (int l = 1; l <= i ; l++) {
				if (a[l] <= a[l + 1]) {
					swap(a[l], a[l + 1]);
				}
			}
		}
	}
	cout << a[1];
	return 0;
}