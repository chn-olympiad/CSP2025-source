#include <bits/stdc++.h>
using namespace std;
long long a[600010];

long long myxor(long long l, long long r) {
	long long sum = a[l];
	for (long long i = l + 1; i <= r; i++) {
		sum = sum ^a[i];
	}
	return sum;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long l = 1, r = 1, sum = 0, maxb = -1;
	for (int i = 1; i <= n; i++) {
		maxb = max(maxb, sum);
		for (int j = 1; j <= n; j++) {
			if (myxor(l, r) == k)
				sum++;
			else if (abs(myxor(l + 1, r) - k) >= abs(myxor(l, r + 1) - k))
				r++;
			else
				l++;
		}
	}
	cout << n;
	return 0;
}
