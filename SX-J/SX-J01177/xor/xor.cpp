#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int a[N], b[N], ma = 0, ii;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	cin >> a[1];
	b[1] = a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i] ^ b[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		ii = i;
		for (int j = n; j >= i; j--) {
			int s = b[j] ^ b[i];
			if (i == j)
				s = b[i];
			if (s == k) {
				ma ++;
				ii = j + 1;
			}

		}
		i = ii;

	}
	cout << ma;
	return 0;
}