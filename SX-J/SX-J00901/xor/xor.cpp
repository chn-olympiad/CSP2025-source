#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[500010], b[500010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int m = 0;
	for (int i = 1; i <= n; i++) {

		cin >> a[i];

		if (a[i] == k && a[i] == 1 || a[i] == k && a[i - 1] != a[i]) {
			m++;
			continue;
		}
		b[i] = b[i - 1] ^ a[i];
		for (int j = 0; j < i; j++) {
			if (abs(b[i] - b[j]) == k && b[i - 1] != k) {
				m++;
				a[i] = k;
				break;
			}

		}
	}
	cout << m;
}