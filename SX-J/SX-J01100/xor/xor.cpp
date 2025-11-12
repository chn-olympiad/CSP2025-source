#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long n;
long long k;
long long b[500005];
long long sum;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k) {
			sum++;
		}
	}
	b[1] = a[1];
	for (int i = 2; i <= n; i++) {
		b[i] = b[i - 1] ^ a[i]; //构造数组
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (b[j]^b[i] == k || a[j] == k) {

				sum++;
				i = j;
				break;
			}
		}
	}
	cout << sum;
	return 0;
}