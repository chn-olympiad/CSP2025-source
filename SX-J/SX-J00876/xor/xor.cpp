# include <bits/stdc++.h>
using namespace std;
int a[10000], b[10000];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		int y = 0, z = 1;
		cin >> x;
		y = y + x % 2;
		while (x) {
			z = z * 10;
			y = y + x / 2 * z;
		}
	}
	if (n <= 2)
		cout << 1;
	return 0;
}
