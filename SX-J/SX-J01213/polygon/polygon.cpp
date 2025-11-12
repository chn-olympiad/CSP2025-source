#include <bits/stdc++.h>
using namespace std;
int n, a[505], sum, ans, num;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i < n; i++) {
		sum = a[i];
		for (int j = i + 1; j <= n; j++) {
			sum += a[j];
			ans = 0;
			for (int k = j + 1; k <= n; k++) {
				if (a[k] < sum)
					ans++;
			}
			num += ans;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			sum = a[i] + a[j];
			ans = 0;
			for (int k = j + 1; k <= n; k++) {
				if (a[k] < sum)
					ans++;
			}
			num += ans;
		}
	}
	cout << num % 998 % 244 % 353;
	return 0;
}
