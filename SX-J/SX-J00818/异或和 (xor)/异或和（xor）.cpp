#include <bits/stdc++.h>
using namespace std;
int a[1000 + 5];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k; i++) {
		if (a[i] < a[i + 1]) {
			cout << a[i + 1];
			break;
		}

		else {
			cout << a[i];
			break;
		}
	}
	if (k = 0) {
		cout << 1;
	}
	return 0;
}
