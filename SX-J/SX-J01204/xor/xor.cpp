#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010], l;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = a[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n;) {
		for (int j = i ; j <= n; j++) {
			if (a[j]^a[i - 1] == k) {
				l++;
				i = j + 1;
				break;
			}
		}
	}
	cout << l;
	return 0;
}
