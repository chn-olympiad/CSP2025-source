#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
int b[N];
int f[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		b[i] = b[i - 1] ^ x;
	}
	for (int i = 1; i <= n; i++) {
		for (int len = 1; len <= i; len++) {
			int nb = b[i] ^ b[i - len];
			if (nb == k) {
				f[i] = max(f[i], f[i - len] + 1);
			} else {
				f[i] = max(f[i], f[i - 1]);
			}
		}
	}
	cout << f[n];
	return 0;
}
