#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int sum[5005];
int ans;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = 1; j + k <= n; k++) {
				if (sum[j + k] - sum[i - 1] > 2 * a[i]) {
					ans += n - (j + k) + 1;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}