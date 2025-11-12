#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005];
long long k;
int x = 0;
int sum = 0;

int check(int i) {
	int b = a[i];
	if (b == k) {
		return i;
	}
	for (; i < n - 1; i++) {
		b = b ^a[i + 1];
		if (b == k) {
			return i + 1;
		}
	}
	return -1;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			x++;
		}
	}
	if (x == n && k == 0) {
		cout << n / 2;
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		x = check(i);
		if (x == -1) {
			cout << sum;
			return 0;
		} else {
			sum++;
			i = x;
		}
	}
	cout << sum;
	return 0;
}
