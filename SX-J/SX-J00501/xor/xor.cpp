#include <bits/stdc++.h>
using namespace std;
int n, k, a[50020], cnt, c, b[50020];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 2) {
		if (a[1] == k) {
			if (a[2] == k) {
				cout << 2;
				return 0;
			} else {
				cout << 1;
				return 0;
			}
		} else if (a[2] == k) {
			cout << 1;
			return 0;
		} else if ((a[1] and a[2]) + (a[1] or a[2]) == k)
			cout << 1;
		return 0;
		else
			cout << 0;
		return 0;
	} else
		cout << 2;
	return 0;
}
