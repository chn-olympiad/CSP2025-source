#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[500015], s;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long p, d = 1;
	for (int i = 1; i <= n; i++) {
		p = a[i];
		if (p == k) {
			s++;
		} else {
			for (int j = i + 1; j <= n; j++) {
				p = (p ^a[j]);
				if (p == k) {
					s++;
					d = j + 1;
					i = d;
					continue;
				}
			}
		}

	}
	cout << s;
	return 0;
}