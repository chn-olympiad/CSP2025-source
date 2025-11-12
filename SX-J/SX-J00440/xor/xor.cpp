#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[1000001];
long long c;
long long k;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; i <= n; i++) {
			c = c ^a[j];
			if (c == m) {
				k++;
			}
		}
		c = 0;
	}
	cout << k;
	return 0;
}
