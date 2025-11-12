#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int a[n + 5] =  {};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 1, r = n, s = 0;
	int j = 0;
	while (l <= r) {
		for (int i = l; i <= r; i++) {
			j = a[i] xor j;
		}
		if (j == k) {
			s++;
		}
		l++;
		j = 0;
	}
	cout << s;
	return 0;
}
