#include <bits/stdc++.h>
using namespace std;
int a[500005], stop[500005];

bool f(int c, int d) {
	for (int j = c; j <= d; j++) {
		for (int i = 0; i < 500005; i++) {
			if (stop[i] == j) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, num = 0, cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			num++;
			stop[cnt] += i;
			cnt++;
		}
	}
	for (int i = 1; i <= n; i++) {
		int b = a[i];
		for (int j = i + 1; j <= n; j++) {
			b = b xor a[j];
			if (b == k && !f(i, j)) {
				num++;
				for (int x = i; x <= j; x++) {
					stop[cnt] += x;
					cnt++;
				}
			}
		}
	}
	cout << num;
	return 0;
}
