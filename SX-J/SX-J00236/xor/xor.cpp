#include <bits/stdc++.h>
using namespace std;
int n, k;
int b[1000000];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	int sum = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			int x = 0;
			for (int i = l; i <= r; i++) {
				x ^= b[i];
			}
			if (x == k) {
				l = r + 1, r = l;
				sum++;
			}

		}
	}
	cout << sum;
	return 0;
}
