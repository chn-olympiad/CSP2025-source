#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, sum = 0;
	cin >> n >> k;
	long a[n];
	long long l = 0, r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (; l < n; l++) {
		int num = a[l];
		for (r = l; r < n; r++) {
			num ^= a[r];
			if (num == k) {
				sum++;
			}
		}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
