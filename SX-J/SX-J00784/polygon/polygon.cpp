#include <bits/stdc++.h>
using namespace std;
int a[5005], sum = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int ans = 0;
			int mmax = 0;
			for (int k = j; k <= j + i; k++) {
				ans += a[k];
				mmax = max(a[k], mmax);
			}
			if (ans > mmax * 2)
				sum++;
		}
	}
	cout << sum;
	return 0;
}
