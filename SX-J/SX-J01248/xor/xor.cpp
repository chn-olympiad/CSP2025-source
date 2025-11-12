#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, xoor = 0;
	long long sum = 0, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	b[0] = -1;
	for (int i = 1; i <= n - 1; i++)
		b[i] = a[i] ^ a[i + 1];
	for (int i = 1; i <= n; i++) {
		xoor = xoor ^a[i];
		if (a[i] == k || ((b[i - 1] == k ) && (a[i - 1] != k)) || xoor == k) {
			sum += 1;
			xoor = 0;
		}
	}
	cout << sum;
	return 0;
}
