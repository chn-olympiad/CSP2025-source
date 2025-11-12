#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, sum = 0, l = 1, r = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	while (l < n) {
		int w = 0;
		for (int i = l; i <= r; i++)
			w = int(w ^ a[i]);
		if (w == k) {
			sum++;
			l = r + 1;
			r = l;
		} else
			r++;
		if (r > n) {
			l++;
			r = n;
		}
	}
	cout << sum;
	return 0;
}
