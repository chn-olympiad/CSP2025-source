#include <bits/stdc++.h>
using namespace std;
int n, ans, a[100];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (i > j + k && i < abs(j - k))
					ans++;
			}
		}
	}
	cout << ans;
	return 0;
}