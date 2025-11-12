#include <bits/stdc++.h>
using namespace std;
int n, k, a[500009], b[500009], ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		b[i] = a[i];
		for (int j = i + 1; j <= n; j++) {
			b[i] = b[i] ^ a[j];
			if (b[i] == k)
				ans++;
		}
	}

	cout << ans;

	return 0;
}
