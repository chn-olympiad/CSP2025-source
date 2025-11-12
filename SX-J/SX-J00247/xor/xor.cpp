#include <bits/stdc++.h>
using namespace std;
long long n, k;
int a[100861];

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (a[i] + a[j] <= k && i != 1 && a[i] + a[j] != 0) {
				cout << a[i];
				return 0;
			}
		}
	}
	cout << 1;
	return 0;
}
