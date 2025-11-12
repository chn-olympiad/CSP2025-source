#include <bits/stdc++.h>
using namespace std;
int n, sum;
unsigned int k, m, x;
unsigned int a[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == k) {
			sum++;
			i++;
		}
		x = a[i] ^ a[i + 1];
		if (x == k) {
			sum++;
			i++;
			break;
		}
		for (int j = i + 2; j < n; j++) {
			x = x ^a[j];
			if (x == k) {
				sum++;
				i = j;
				break;
			}
		}
	}
	cout << sum;
	return 0;
}
