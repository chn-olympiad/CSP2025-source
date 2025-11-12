#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int a[n + 2], x[n + 1];
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = 0;
		cin >> a[i];
	}
	a[n + 1] = a[n];
	sort(a + 1, a + n + 1);
	x[0] = 0;
	for (int i = 1; i <= n; i++) {
		x[i] = 0;
		x[i] = x[i - 1] + a[i];
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= n; i++) {
		cout << x[i] << " ";
		int j = 0;
		if (j < i && x[i] - x[j] > a[i + 1]) {
			j = 1;
			while (j < i - 2 && x[i] - x[j + 1] > a[i + 1]) {
				j++;
			}
		}
		ans = ans + j;
	}
	cout << ans;
	return 0;
}
