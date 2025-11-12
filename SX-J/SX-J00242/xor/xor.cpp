#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010];

bool yh(int i, int j) {
	int sum = a[i];
	for (int g = i + 1; g <= j; g ++) {
		sum = sum ^a[g];
	}
	return sum == k;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	int sum = 0, l = n + 1, r = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j++) {
			if (yh(i, j)) {
				if ((i >= r && j >= i) || (i <= l && j >= i && j <= l)) {
					sum++;
					l = min(l, i);
					r = max(r, j);
				}
			}
		}
	}
	cout << sum;
	return 0;
}