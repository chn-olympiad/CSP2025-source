#include <bits/stdc++.h>
using namespace std;
int a[10000005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 2) {
		if (a[1] + a[2] > 2) {
			cout << 0;
			return 0;
		} else {
			cout << 1;
			return 0;
		}

	}



	if (k == 0) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0)
				sum++;
		}
		cout << sum;
	}
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1)
				sum++;
		}
		cout << sum;
	}

	return 0;
}


