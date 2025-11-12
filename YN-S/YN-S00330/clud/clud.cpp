#include <bits/stdc++.h>
using namespace std;
int t, n, A, B, C, j;
int sum = 0;
int a[20005], b[20005], c[20005];
int q = 1;

int main() {
	freopen("clud.in", "r", stdin);
	freopen("clud.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j] >> b[j] >> c[j];
		}
		for (int x = 0; x + 1 <= n; x++) {
			if (a[x] < a[x + 1]) {
				continue;
			} else {
				q = a[x + 1];
				a[x + 1] = a[x];
				a[x] = q;
			}
		}
		for (int i = 0; i < n / 2; i++) {
			sum += a[n - i];
		}
		cout << sum << endl;
	}
	return 0;
}