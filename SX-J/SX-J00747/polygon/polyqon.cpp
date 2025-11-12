#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[5005], s[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 0; j <= i - 2 ; j++) {
			if (s[i] - s[j - 1] > a[i] * 2) {
				ans++;
				cout << i << j << "\n";
			}
		}
	}
	cout << ans;
	return 0;
}
